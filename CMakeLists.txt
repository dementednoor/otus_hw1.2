cmake_minimum_required(VERSION 3.2)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})

project(ip_filter VERSION ${PROJECT_VESRION})

add_executable(ip_filter ip_filter.cpp)
add_executable(test_ip_filter test_ip_filter.cpp)

set_target_properties(ip_filter test_ip_filter PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

target_include_directories(ip_filter
    PRIVATE "${CMAKE_BINARY_DIR}"
)

# set(TEST_SRCS test_ip_filter.cpp ip_filter.cpp)


if (MSVC)
    target_compile_options(ip_filter PRIVATE
        /W4
    )
    target_compile_options(ip_filter PRIVATE
        /W4
    )
    target_compile_options(test_ip_filter PRIVATE
        /W4
    )
else ()
    target_compile_options(ip_filter PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(test_ip_filter PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()

include(GoogleTest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

enable_testing()

target_link_libraries(
        test_ip_filter
        gtest
        gtest_main
        pthread
)

gtest_discover_tests(test_ip_filter)