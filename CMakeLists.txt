cmake_minimum_required( VERSION 3.21 )

set( MAZEGEN_LIBRARY mazegen )
option( MAZEGEN_BUILD_EXAMPLES "Build the examples for this project" OFF )

project( ${MAZEGEN_LIBRARY} VERSION 0.1.0 LANGUAGES CXX )

file( GLOB MAZEGEN_SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cxx )

add_library( ${PROJECT_NAME} ${MAZEGEN_SRC_FILES} )
target_include_directories( ${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include )

if( MAZEGEN_BUILD_EXAMPLES )
    add_subdirectory( ${CMAKE_CURRENT_SOURCE_DIR}/examples )
endif()
