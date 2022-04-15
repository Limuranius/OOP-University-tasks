include_directories(${TASKS_DIR}/calculating-machine)
add_executable(CalcMachine ${TASKS_DIR}/calculating-machine/calc-machine-main.cpp)
add_library(CalcMachineLib ${TASKS_DIR}/calculating-machine/calc-machine.cpp)
target_link_libraries(CalcMachine CalcMachineLib bigIntLib stackLib keyValLib)

add_executable(CalcMachineTest ${TASKS_DIR}/calculating-machine/calc-machine-tests.cpp)
target_link_libraries(CalcMachineTest CalcMachineLib bigIntLib loggerLib gtest gtest_main)

file(COPY
        ${CMAKE_CURRENT_SOURCE_DIR}/calculating-machine/commands1.txt
        ${CMAKE_CURRENT_SOURCE_DIR}/calculating-machine/commands2.txt
        ${CMAKE_CURRENT_SOURCE_DIR}/calculating-machine/commandsIncorrect1.txt
        ${CMAKE_CURRENT_SOURCE_DIR}/calculating-machine/commandsIncorrect2.txt
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})


