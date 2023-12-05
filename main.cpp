#include <iostream>
#include <map>
#include <string>

//Ejercicio 1: Estructura básica
class environment {
    private:
        std::map<std::string, std::string> env;

    public:
        void insert(const std::string& variable, const std::string& value) {

            if (env.find(variable) == env.end()) {
                env.insert(std::pair<std::string, std::string>(variable, value));
            } else {
                env[variable] = value;
            }
        }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

