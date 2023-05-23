include(FindPackageHandleStandardArgs)

macro(_Sphinx_find_executable _exe)
    string(TOUPPER "${_exe}" _uc)
    find_program(
        SPHINX_${_uc}_EXECUTABLE
        NAMES "sphinx-${_exe}-3" "sphinx-${_exe}" "sphinx-${_exe}.exe")

    if(SPHINX_${_uc}_EXECUTABLE)
        execute_process(
        COMMAND "${SPHINX_${_uc}_EXECUTABLE}" --version
        RESULT_VARIABLE _result
        OUTPUT_VARIABLE _output
        OUTPUT_STRIP_TRAILING_WHITESPACE)
        if(_result EQUAL 0 AND _output MATCHES " v?([0-9]+\\.[0-9]+\\.[0-9]+)$")
        set(SPHINX_${_uc}_VERSION "${CMAKE_MATCH_1}")
        endif()

        if(NOT TARGET Sphinx::${_exe})
        add_executable(Sphinx::${_exe} IMPORTED GLOBAL)
        set_target_properties(Sphinx::${_exe} PROPERTIES
            IMPORTED_LOCATION "${SPHINX_${_uc}_EXECUTABLE}")
        endif()
        set(Sphinx_${_exe}_FOUND TRUE)
    else()
        set(Sphinx_${_exe}_FOUND FALSE)
    endif()
    unset(_uc)
endmacro()

macro(_Sphinx_find_module _name _module)
    string(TOUPPER "${_name}" _Sphinx_uc)
    if(SPHINX_PYTHON_EXECUTABLE)
        execute_process(
        COMMAND ${SPHINX_PYTHON_EXECUTABLE} -m ${_module} --version
        RESULT_VARIABLE _result
        OUTPUT_VARIABLE _output
        OUTPUT_STRIP_TRAILING_WHITESPACE
        ERROR_QUIET)
        if(_result EQUAL 0)
        if(_output MATCHES " v?([0-9]+\\.[0-9]+\\.[0-9]+)$")
            set(SPHINX_${_Sphinx_uc}_VERSION "${CMAKE_MATCH_1}")
        endif()

        if(NOT TARGET Sphinx::${_name})
            set(SPHINX_${_Sphinx_uc}_EXECUTABLE "${SPHINX_PYTHON_EXECUTABLE} -m ${_module}")
            add_executable(Sphinx::${_name} IMPORTED GLOBAL)
            set_target_properties(Sphinx::${_name} PROPERTIES
            IMPORTED_LOCATION "${SPHINX_PYTHON_EXECUTABLE}")
        endif()
        set(Sphinx_${_name}_ARGS -m ${_module})
        set(Sphinx_${_name}_FOUND TRUE)
        else()
        set(Sphinx_${_name}_FOUND FALSE)
        endif()
    else()
        set(Sphinx_${_name}_FOUND FALSE)
    endif()
    unset(_Sphinx_uc)
endmacro()

macro(_Sphinx_find_extension _ext)
    if(SPHINX_PYTHON_EXECUTABLE)
        execute_process(
        COMMAND ${SPHINX_PYTHON_EXECUTABLE} -c "import ${_ext}"
        RESULT_VARIABLE _result)
        if(_result EQUAL 0)
        set(Sphinx_${_ext}_FOUND TRUE)
        else()
        set(Sphinx_${_ext}_FOUND FALSE)
        endif()
    endif()
endmacro()

_Sphinx_find_executable(build)

if(SPHINX_BUILD_EXECUTABLE)
    _Sphinx_find_executable(quickstart)

    file(READ "${SPHINX_BUILD_EXECUTABLE}" _Sphinx_script)
    if(_Sphinx_script MATCHES "^#!([^\n]+)")
        string(STRIP "${CMAKE_MATCH_1}" _Sphinx_shebang)
        if(EXISTS "${_Sphinx_shebang}")
            set(SPHINX_PYTHON_EXECUTABLE "${_Sphinx_shebang}")
        endif()
    endif()
    unset(_Sphinx_script)
    unset(_Sphinx_shebang)
endif()

if(NOT SPHINX_PYTHON_EXECUTABLE)
    find_package(Python3 QUIET COMPONENTS Interpreter)
    if(TARGET Python3::Interpreter)
        set(SPHINX_PYTHON_EXECUTABLE ${Python3_EXECUTABLE})
        if(NOT SPHINX_BUILD_EXECUTABLE)
        _Sphinx_find_module(build sphinx)
        _Sphinx_find_module(quickstart sphinx.cmd.quickstart)
        endif()
    endif()
endif()

if(SPHINX_BUILD_VERSION)
    if("exhale"  IN_LIST Sphinx_FIND_COMPONENTS AND NOT
        "breathe" IN_LIST Sphinx_FIND_COMPONENTS)
        list(APPEND Sphinx_FIND_COMPONENTS "breathe")
    endif()

    foreach(_Sphinx_component IN LISTS Sphinx_FIND_COMPONENTS)
        if(_Sphinx_component STREQUAL "build")
        continue()
        elseif(_Sphinx_component STREQUAL "quickstart")
        continue()
        endif()
        _Sphinx_find_extension(${_Sphinx_component})
    endforeach()
    unset(_Sphinx_component)

    if(SPHINX_QUICKSTART_VERSION AND NOT SPHINX_BUILD_VERSION STREQUAL SPHINX_QUICKSTART_VERSION)
        message(FATAL_ERROR "Versions for sphinx-build (${SPHINX_BUILD_VERSION}) "
                            "and sphinx-quickstart (${SPHINX_QUICKSTART_VERSION}) "
                            "do not match")
    endif()
endif()

find_package_handle_standard_args(
    Sphinx
    VERSION_VAR SPHINX_BUILD_VERSION
    REQUIRED_VARS SPHINX_BUILD_EXECUTABLE SPHINX_BUILD_VERSION
    HANDLE_COMPONENTS
)

function(_Sphinx_generate_confpy _target _cachedir)
    if(NOT TARGET Sphinx::quickstart)
        message(FATAL_ERROR "sphinx-quickstart is not available, needed by"
                            "sphinx_add_docs for target ${_target}")
    endif()

    if(NOT DEFINED SPHINX_PROJECT)
        set(SPHINX_PROJECT ${PROJECT_NAME})
    endif()

    if(NOT DEFINED SPHINX_AUTHOR)
        set(SPHINX_AUTHOR "${SPHINX_PROJECT} committers")
    endif()

    if(NOT DEFINED SPHINX_COPYRIGHT)
        string(TIMESTAMP "%Y, ${SPHINX_AUTHOR}" SPHINX_COPYRIGHT)
    endif()

    if(NOT DEFINED SPHINX_VERSION)
        set(SPHINX_VERSION "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}")
    endif()

    if(NOT DEFINED SPHINX_RELEASE)
        set(SPHINX_RELEASE "${PROJECT_VERSION}")
    endif()

    if(NOT DEFINED SPHINX_LANGUAGE)
        set(SPHINX_LANGUAGE "en")
    endif()

    if(NOT DEFINED SPHINX_MASTER)
        set(SPHINX_MASTER "index")
    endif()

    set(_known_exts autodoc doctest intersphinx todo coverage imgmath mathjax
                    ifconfig viewcode githubpages)

    if(DEFINED SPHINX_EXTENSIONS)
        foreach(_ext ${SPHINX_EXTENSIONS})
        set(_is_known_ext FALSE)
        foreach(_known_ext ${_known_exsts})
            if(_ext STREQUAL _known_ext)
            set(_opts "${opts} --ext-${_ext}")
            set(_is_known_ext TRUE)
            break()
            endif()
        endforeach()
        if(NOT _is_known_ext)
            if(_exts)
            set(_exts "${_exts},${_ext}")
            else()
            set(_exts "${_ext}")
            endif()
        endif()
        endforeach()
    endif()

    if(_exts)
        set(_exts "--extensions=${_exts}")
    endif()

    set(_templatedir "${CMAKE_CURRENT_BINARY_DIR}/${_target}.template")
    file(MAKE_DIRECTORY "${_templatedir}")
    string(REPLACE " " ";" _Sphinx_executable ${SPHINX_QUICKSTART_EXECUTABLE})
    execute_process(
        COMMAND ${_Sphinx_executable}
                -q --no-makefile --no-batchfile
                -p "${SPHINX_PROJECT}"
                -a "${SPHINX_AUTHOR}"
                -v "${SPHINX_VERSION}"
                -r "${SPHINX_RELEASE}"
                -l "${SPHINX_LANGUAGE}"
                --master "${SPHINX_MASTER}"
                ${_opts} ${_exts} "${_templatedir}"
        RESULT_VARIABLE _result
        OUTPUT_QUIET)
    unset(_Sphinx_executable)

    if(_result EQUAL 0 AND EXISTS "${_templatedir}/conf.py")
        file(COPY "${_templatedir}/conf.py" DESTINATION "${_cachedir}")
    endif()

    file(REMOVE_RECURSE "${_templatedir}")

    if(NOT _result EQUAL 0 OR NOT EXISTS "${_cachedir}/conf.py")
        message(FATAL_ERROR "Sphinx configuration file not generated for "
                            "target ${_target}")
    endif()
endfunction()

function(sphinx_add_docs _target)
    set(_opts)
    set(_single_opts BUILDER OUTPUT_DIRECTORY SOURCE_DIRECTORY)
    set(_multi_opts BREATHE_PROJECTS)
    cmake_parse_arguments(_args "${_opts}" "${_single_opts}" "${_multi_opts}" ${ARGN})

    unset(SPHINX_BREATHE_PROJECTS)

    if(NOT _args_BUILDER)
        message(FATAL_ERROR "Sphinx builder not specified for target ${_target}")
    elseif(NOT _args_SOURCE_DIRECTORY)
        message(FATAL_ERROR "Sphinx source directory not specified for target ${_target}")
    else()
        if(NOT IS_ABSOLUTE "${_args_SOURCE_DIRECTORY}")
        get_filename_component(_sourcedir "${_args_SOURCE_DIRECTORY}" ABSOLUTE)
        else()
        set(_sourcedir "${_args_SOURCE_DIRECTORY}")
        endif()
        if(NOT IS_DIRECTORY "${_sourcedir}")
        message(FATAL_ERROR "Sphinx source directory '${_sourcedir}' for"
                            "target ${_target} does not exist")
        endif()
    endif()

    set(_builder "${_args_BUILDER}")
    if(_args_OUTPUT_DIRECTORY)
        set(_outputdir "${_args_OUTPUT_DIRECTORY}")
    else()
        set(_outputdir "${CMAKE_CURRENT_BINARY_DIR}/${_target}")
    endif()

    if(_args_BREATHE_PROJECTS)
        if(NOT Sphinx_breathe_FOUND)
        message(FATAL_ERROR "Sphinx extension 'breathe' is not available. Needed"
                            "by sphinx_add_docs for target ${_target}")
        endif()
        list(APPEND SPHINX_EXTENSIONS breathe)

        foreach(_doxygen_target ${_args_BREATHE_PROJECTS})
            if(TARGET ${_doxygen_target})
                list(APPEND _depends ${_doxygen_target})

                get_target_property(_dir ${_doxygen_target} BINARY_DIR)
                set(_doxyfile "${_dir}/Doxyfile.${_doxygen_target}")
                if(NOT EXISTS "${_doxyfile}")
                message(FATAL_ERROR "Target ${_doxygen_target} is not a Doxygen"
                                    "target, needed by sphinx_add_docs for target"
                                    "${_target}")
                endif()

                file(READ "${_doxyfile}" _contents)
                if(NOT _contents MATCHES "GENERATE_XML *= *YES")
                message(FATAL_ERROR "Doxygen target ${_doxygen_target} does not"
                                    "generate XML, needed by sphinx_add_docs for"
                                    "target ${_target}")
                elseif(_contents MATCHES "OUTPUT_DIRECTORY *= *([^ ][^\n]*)")
                string(STRIP "${CMAKE_MATCH_1}" _dir)
                set(_name "${_doxygen_target}")
                set(_dir "${_dir}/xml")
                else()
                message(FATAL_ERROR "Cannot parse Doxyfile generated by Doxygen"
                                    "target ${_doxygen_target}, needed by"
                                    "sphinx_add_docs for target ${_target}")
                endif()
            elseif(_doxygen_target MATCHES "([^: ]+) *: *(.*)")
                set(_name "${CMAKE_MATCH_1}")
                string(STRIP "${CMAKE_MATCH_2}" _dir)
            endif()

            if(_name AND _dir)
                if(_breathe_projects)
                set(_breathe_projects "${_breathe_projects}, \"${_name}\": \"${_dir}\"")
                else()
                set(_breathe_projects "\"${_name}\": \"${_dir}\"")
                endif()
                if(NOT _breathe_default_project)
                set(_breathe_default_project "${_name}")
                endif()
            endif()
        endforeach()
    endif()

    set(_cachedir "${CMAKE_CURRENT_BINARY_DIR}/${_target}.cache")
    file(MAKE_DIRECTORY "${_cachedir}")
    file(MAKE_DIRECTORY "${_cachedir}/_static")
    _Sphinx_generate_confpy(${_target} "${_cachedir}")

    if(_breathe_projects)
        file(APPEND "${_cachedir}/conf.py"
        "\nbreathe_projects = { ${_breathe_projects} }"
        "\nbreathe_default_project = '${_breathe_default_project}'")
    endif()

    string(REPLACE " " ";" _Sphinx_executable ${SPHINX_BUILD_EXECUTABLE})
    add_custom_target(
        ${_target}
        COMMAND ${_Sphinx_executable}
                -b ${_builder}
                -d "${CMAKE_CURRENT_BINARY_DIR}/${_target}.cache/_doctrees"
                -c "${CMAKE_CURRENT_BINARY_DIR}/${_target}.cache"
                "${_sourcedir}"
                "${_outputdir}"
        DEPENDS ${_depends})
    unset(_Sphinx_executable)
endfunction()
