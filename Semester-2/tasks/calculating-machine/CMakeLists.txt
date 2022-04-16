include_directories(.)
add_executable(CalcMachine calc-machine-main.cpp)
add_library(CalcMachineLib calc-machine.cpp)
target_link_libraries(CalcMachine CalcMachineLib bigIntLib stackLib keyValLib)

add_executable(CalcMachineTest calc-machine-tests.cpp)
target_link_libraries(CalcMachineTest CalcMachineLib bigIntLib loggerLib gtest gtest_main)

file(COPY
        commands1.txt
        commands2.txt
        commandsIncorrect1.txt
        commandsIncorrect2.txt
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})