set(lib_sources
    "${CMAKE_CURRENT_SOURCE_DIR}/color_conversion.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/image.cpp"
)

target_sources(${lib_name} PRIVATE ${lib_sources})
