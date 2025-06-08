
#ifndef DATABASE_H
#define DATABASE_H

#include <string>

// Declaración de clase Database
class Database {
    public:
        // Destructor
        virtual ~Database() = default;

        // Función virtual para verificar la existencia de un usuario en la base de datos
        virtual bool userExists(const std::string& username) = 0;

        // Función virtual para obtener la contraseña de un usuario basado en su username
        virtual std::string getPassword(const std::string& username) = 0;

        // Función virtual para agregar un usuario
        virtual void addUser(const std::string& username, const std::string& password) = 0;
};

#endif 