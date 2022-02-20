cmake_minimum_required(VERSION 3.21)

# set the project name
project(square_pixels)

include(cmake/config.cmake)
include(cmake/options.cmake)
add_subdirectory(3rdparty)

set(lib_name ${CMAKE_PROJECT_NAME})
add_library(${lib_name})

add_subdirectory(src)
target_include_directories(${lib_name}
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

add_subdirectory(include)
set_target_properties(${lib_name} PROPERTIES PUBLIC_HEADER "${lib_public_headers}")

install(TARGETS ${lib_name} PUBLIC_HEADER
DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${lib_name})

if(BUILD_TESTS)
    add_subdirectory(tests)
endif()
