#include <iostream>
#include <map>
#include <string>

//Ejercicio 1: Estructura básica
class environment {
    private:
        std::map<std::string, std::string> env;
//Ejercicio 2:
    public:
        void insert(const std::string& variable, const std::string& value) {

            if (env.find(variable) == env.end()) {
                env[variable] = value;
                std::cout << "Variable '" << variable << "' added to environment with value: " << value << std::endl;

            } else {
                std::cerr << "Variable '" << variable << "' already exists in the environment." << std::endl;

            }
        }
//ejercicio 3
        std::string lookup (const std::string& variable) {
            if (env.find(variable) != env.end()) {
                return env[variable];
            } else {
                std::cerr << "Variable '" << variable << "' does not exist in the environment." << std::endl;
                return "";
            }
        }
};


int main() {
//ejercicio 2
    environment env;

          env.insert("Person_age", "20");
          env.insert("Person_name", "Fran");
          env.insert("Person_height", "1.74");

//ejercicio 3
    std::cout << "Person_age: " << env.lookup("Person_age") << std::endl;
    std::cout << "Person_gender: " << env.lookup("Person_gender") << std::endl; //Este devolvera que no exite
    return 0;

}

