#include "authorizer.h"

Authorizer::Authorizer(LoggerInterface *logger, const string &DB_path) {
    this->logger = logger;
    this->DB_path = DB_path;
    this->parser = Parser();
    this->converter = CSV_KeyVal_Converter();
    this->users_DB = this->converter.vector_to_dict(
            this->parser.parse(DB_path)
    );
}

bool Authorizer::name_exist(const string &username) {
    return this->users_DB.has(username);
}

bool Authorizer::is_password_correct(const string &username, const string &password) {
    return this->users_DB[username] == this->to_hash(password);
}

void Authorizer::register_user() {
    this->logger->log_info("Registering a user");

    string username;
    bool username_success = false;
    while (!username_success) {
        cout << "Username:\n";
        getline(cin, username);

        if (!this->name_exist(username))
            username_success = true;
        else
            this->logger->log_error("This username is already taken");

    }

    string password1;
    string password2;
    bool password_success = false;
    while (!password_success) {
        cout << "Password:\n";
        getline(cin, password1);
        cout << "Repeat password:\n";
        getline(cin, password2);

        if (password1 == password2)
            password_success = true;
        else
            this->logger->log_error("Passwords do not match");
    }

    this->register_user(username, password1);

    this->logger->log_info("Registration successful");
}

void Authorizer::register_user(const string &username, const string &password) {
    this->users_DB[username] = this->to_hash(password);
    this->update_DB_file();
}

void Authorizer::log_in_user() {
    this->logger->log_info("Logging in a user");

    string username;
    bool username_success = false;
    while (!username_success) {
        cout << "Username:\n";
        getline(cin, username);

        if (this->name_exist(username))
            username_success = true;
        else
            this->logger->log_error("This username does not exist");
    }

    string password;
    bool password_success = false;
    while (!password_success) {
        cout << "Password:\n";
        getline(cin, password);

        if (this->is_password_correct(username, password))
            password_success = true;
        else {
            this->logger->log_error("Password is incorrect");
            cout << "Needed: " << this->users_DB[username] << endl;
            cout << "Got: " << to_hash(password) << endl;
        }
    }

    this->logger->log_info("Logged in successfully");

}

string Authorizer::to_hash(const string &str) {
    return std::to_string(hashFunction(str));
}

long long hashFunction(const string& key) {
    long long hashCode = 0;
    int bits_per_char = (64 - 4) / key.size();
    bits_per_char += bits_per_char == 0;
    for (int i = 0; i < key.length(); i++) {
        int curr = key[i];
        for (int j = 0; j < bits_per_char; j++) {
            hashCode += (curr % 2) == 0;
            hashCode <<= 1;
            curr /= 2;
        }
    }
    return hashCode;
}

void Authorizer::update_DB_file() {
    this->parser.write_to_file(
            this->converter.dict_to_vector(this->users_DB),
            this->DB_path
    );
}

Authorizer BasicAuthorizerFactory::create(const string &DB_path) {
    CombinedLoggerFactory factory;
    auto logger = factory.createLogger();

    return Authorizer(logger, DB_path);
}
