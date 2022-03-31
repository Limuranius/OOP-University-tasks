#include <iostream>
#include "logger.h"

int main() {
    auto factory = new ConsoleLoggerFactory();
    log(factory, "aboba");
}