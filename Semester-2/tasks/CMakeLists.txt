include_directories(${TASKS_DIR}/calculating-machine)
add_executable(CalcMachine ${TASKS_DIR}/calculating-machine/calc-machine-main.cpp)
add_library(CalcMachineLib ${TASKS_DIR}/calculating-machine/calc-machine.cpp)
target_link_libraries(CalcMachine CalcMachineLib bigIntLib stackLib keyValLib)


