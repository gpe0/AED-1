#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H

#include <vector>
#include <string>
#include <fstream>
#include <sstream>

class Authentication {
private:
    std::string name, status;
    std::vector<std::pair<std::string, std::string>> getAllUsersOfType(std::string status);
public:
    Authentication(std::string status, std::string name, std::string password);

    std::string getName();
    std::string getStatus();

    class AuthenticationError {
    private:
        std::string msg;
    public:
        AuthenticationError(std::string msg) {this->msg = msg;};
        std::string what() const {return msg;};
    };
};


#endif
