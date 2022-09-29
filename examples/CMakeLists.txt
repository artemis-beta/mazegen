file( GLOB MAZEGEN_EXAMPLE_SRCS ${CMAKE_CURRENT_SOURCE_DIR}/*.cxx )

foreach( EXAMPLE ${MAZEGEN_EXAMPLE_SRCS} )
    get_filename_component( BINARY ${EXAMPLE} NAME_WLE )
    add_executable( ${BINARY} ${EXAMPLE} )
    target_link_libraries( ${BINARY} PUBLIC ${PROJECT_NAME} )
    target_include_directories( ${BINARY} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include )
endforeach()
