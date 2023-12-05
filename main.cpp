#include <iostream>
#include <map>
#include <string>
#include <stdexcept>

//Ejercicio 1: Estructura básica
class environment {
    private:
        std::map<std::string, std::string> env;

//Ejercicio 2:Insertar Símbolos
    public:
        void insert(const std::string& variable, const std::string& value) {

            if (env.find(variable) == env.end()) {
                env[variable] = value;
                std::cout << "Variable '" << variable << "' added to environment with value: " << value << std::endl;

            }
            else {
//Ejercicio 4: Gestión de Errores
                if (env[variable] != value) {
                    throw std::invalid_argument("Variable '" + variable + "' already exists in the environment with a different value.");

                }
                else {
                    std::cout << "Variable '" << variable << "' already exists in the environment with the same value." << std::endl;
                }
            }
        }

//ejercicio 3: Búsqueda de Símbolos:
        std::string lookup (const std::string& variable) {
            if (env.find(variable) != env.end()) {
                return env[variable];
            }
            else {
                throw std::invalid_argument("Variable '" + variable + "' does not exist in the environment.");
            }
        }

        void remove(const std::string& variable) {
            auto it = env.find(variable);
            if (it != env.end()) {
                env.erase(it);
                std::cout << "Variable '" << variable << "' removed from environment." << std::endl;
            } else {
                throw std::invalid_argument("Variable '" + variable + "' does not exist in the environment. Cannot remove.");
            }
        }
    bool exists(const std::string& variable) {
        return env.find(variable) != env.end();
    }
};


int main() {
//ejercicio 2: Insertar Símbolos
    environment env;
        try { //ejercicio 4
            env.insert("Person_age", "20");
            env.insert("Person_name", "Fran");
            env.insert("Person_height", "1.74");

            //ejercicio 3: Búsqueda de Símbolos:
            std::cout << "Person_age: " << env.lookup("Person_age") << std::endl;
            std::cout << "Person_gender exists? " << (env.exists("Person_gender") ? "Yes" : "No") << std::endl;

            //Ejercicio 6:Expandiendo Funcionalidades
        env.remove("Person_age");
        std::cout << "Person_age: " << env.lookup("Person_age") << std::endl; //Este devolvera ahora que no exite

            //ejercicio 4: Gestión de Errores
            }
            catch (const std::invalid_argument& e) {
                std::cout << e.what() << std::endl;
            }
return 0;

}

