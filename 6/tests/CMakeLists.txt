add_subdirectory(googletest)
include_directories(..)

add_executable(tests tests.cpp)

target_link_libraries(tests coder gtest gtest_main)