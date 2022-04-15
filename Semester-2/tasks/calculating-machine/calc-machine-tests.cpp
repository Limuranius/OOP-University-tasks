#include "gtest/gtest.h"
#include "calc-machine.h"
#include "logger.h"

TEST(CALC_MACHINE_TEST, FILE_NOT_EXIST) {
    NoLogCalculatorFactory factory;
    auto calculator = factory.create();

    EXPECT_ANY_THROW(
            calculator->read_commands_from_file("sjdflsdjhslkvbsdklfhdflkef.txt")
    );
}

TEST(CALC_MACHINE_TEST, INCORRECT_FILES) {
    NoLogCalculatorFactory factory;
    auto calculator = factory.create();

    EXPECT_ANY_THROW(
            calculator->read_commands_from_file("commandsIncorrect1.txt")
    );
    EXPECT_ANY_THROW(
            calculator->read_commands_from_file("commandsIncorrect2.txt")
    );
}

TEST(CALC_MACHINE_TEST, CORRECT_FILE_1) {
    NoLogCalculatorFactory factory;
    auto calculator = factory.create();

    calculator->read_commands_from_file("commands1.txt");
    calculator->run();
    EXPECT_EQ(calculator->get_curr_value().toString(), "-4946311122831214744257652857926133547656672585793473042734766");
}

TEST(CALC_MACHINE_TEST, CORRECT_FILE_2) {
    NoLogCalculatorFactory factory;
    auto calculator = factory.create();

    calculator->read_commands_from_file("commands2.txt");
    calculator->run();
    EXPECT_EQ(calculator->get_curr_value().toString(), "29334940696559855184420254811072212");
}