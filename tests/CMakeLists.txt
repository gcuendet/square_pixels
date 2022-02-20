set(tests_name "unit_tests_square_pixels")

add_executable(
    ${tests_name}
    "${CMAKE_CURRENT_SOURCE_DIR}/unit/test_print.cpp"
)

target_link_libraries(
    ${tests_name}
    ${lib_name}
    gtest_main
)

# Copy the test resources to the build folder
configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/resources/Bouvier_Bernois_BE.jpeg"
    "${CMAKE_BINARY_DIR}/Bouvier_Bernois_BE.jpeg" COPYONLY
)
configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/resources/color_circle.png"
    "${CMAKE_BINARY_DIR}/color_circle.png" COPYONLY
)

gtest_discover_tests(${tests_name}
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_BINARY_DIR}"
)

install(TARGETS ${tests_name})