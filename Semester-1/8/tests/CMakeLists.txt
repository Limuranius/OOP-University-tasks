add_subdirectory(googletest)

include_directories(${CONSOLE_MANAGER_DIR} ${RPN_DIR})
add_executable(test tests.cpp)

target_link_libraries(test polska gtest gtest_main)