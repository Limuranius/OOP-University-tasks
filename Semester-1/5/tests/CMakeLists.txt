add_subdirectory(googletest)

add_executable(test tests.cpp)
include_directories(${MATRIX_INCLUDE_DIR})

target_link_libraries(test matrix gtest gtest_main)