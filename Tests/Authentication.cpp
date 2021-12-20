#include "Authentication.h"

using namespace std;

Authentication::Authentication(std::string status, std::string name, std::string password) {
    vector<pair<string, string>> users;
    if (status == "Client" or status == "Employee" or status == "Admin")
        users = getAllUsersOfType(status);
    else
        throw(AuthenticationError("'" + status + "' isn't a valid user type"));
    for(size_t i = 0; i < users.size(); i++){
        if(users[i].first == name and users[i].second == password){
            this->name = name;
            this->status = status;
            return;
        }
    }
    throw(AuthenticationError("No users with given credentials were found"));
}

std::vector<std::pair<std::string, std::string>> Authentication::getAllUsersOfType(std::string status) {
    std::vector<std::pair<std::string, std::string>> result;
    string file = "../files/Authentication/" + status + "List.csv", line;
    ifstream fileStream(file);
    getline(fileStream, line);   //Skips the first line
    if (!fileStream.is_open()) {
        throw(AuthenticationError("Problem opening the " + status+ " file"));
    }
    while (getline(fileStream, line)) {
        stringstream lineStream(line);
        pair<string, string> element;
        getline(lineStream, element.first, ','); //name
        getline(lineStream, element.second, ','); //password
        result.push_back(element);
    }
    return result;
}

std::string Authentication::getName() {
    return name;
}

std::string Authentication::getStatus() {
    return status;
}

void Authentication::addLog(std::string text) {
    string file = "../files/Authentication/" + status + name + "Logs.txt", line;
    //Complete
}

void Authentication::resetLogs() {
    string file = "../files/Authentication/" + status + name + "Logs.txt";
    const char* pointerToFile = file.c_str();
    remove(pointerToFile);
}

void Authentication::outputLogs(string name) {
    if (status != "Admin"){
        throw(AuthenticationError("User doesn't have permission to read logs"));
    }
    string fileSource = "../files/Authentication/Employee" + name + "Logs.txt";
    addLog("Admin " + name + " read logs from this user"); //HERE
    string fileDestination = "../files/Output/Employee" + name + "Logs.txt";
    std::ifstream  source(fileSource, ios::binary);
    std::ofstream  destination(fileDestination, ios::binary);
    destination << source.rdbuf();
}

void Authentication::outputAllLogs() {
    vector<pair<string, string>> employeeList = getAllUsersOfType("Employee");
    for(size_t i = 0; i < employeeList.size(); i++)
        outputLogs(employeeList[i].first);
}
