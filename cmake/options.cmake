option(BUILD_TESTS "Build tests" ON)

if (${BUILD_TESTS})
    enable_testing()
    include(GoogleTest)
endif()
