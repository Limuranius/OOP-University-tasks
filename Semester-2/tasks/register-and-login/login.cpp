#include "authorizer.h"
#include <string>

int main() {
    std::string filename = "users.txt";
    BasicAuthorizerFactory factory;
    auto auth = factory.create(filename);

    auth.log_in_user();
}
