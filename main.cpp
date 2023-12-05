#include <iostream>
#include <map>
#include <string>
#include <variant>
#include <stdexcept>

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
//Ejercicio 4:
                if (env[variable] != value) {
                    throw std::invalid_argument("Variable '" + variable + "' already exists in the environment with a different value.");

                }
                else {
                    std::cout << "Variable '" << variable << "' already exists in the environment with the same value." << std::endl;
                }
            }
        }

//ejercicio 3
        std::string lookup (const std::string& variable) {
            if (env.find(variable) != env.end()) {
                return env[variable];
            }
            else {
                throw std::invalid_argument("Variable '" + variable + "' does not exist in the environment.");
            }
        }
};


int main() {
//ejercicio 2
    environment env;
        try { //ejercicio 4
            env.insert("Person_age", "20");
            env.insert("Person_name", "Fran");
            env.insert("Person_height", "1.74");

            //ejercicio 3
            std::cout << "Person_age: " << env.lookup("Person_age") << std::endl;
            std::cout << "Person_gender: " << env.lookup("Person_gender") << std::endl; //Este devolvera que no exite
        }
        catch (const std::invalid_argument& e) { //ejercicio 4
            std::cout << e.what() << std::endl;
        }
return 0;

}

