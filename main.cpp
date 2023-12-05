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
                env[variable] = value;
                std::cout << "Variable '" << variable << "' added to environment with value: " << value << std::endl;

            } else {
                std::cerr << "Variable '" << variable << "' already exists in the environment." << std::endl;

            }
        }
};


int main() {

    environment env;


    return 0;
}

