#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H

#include <string>
#include "database.h"

// Clase Authentication
class Authentication {
    public:
        // Constructor de la clase: Recibe una instancia de la base de datos
        Authentication(Database* db) : db_(db) {}

        // Método para iniciar sesión 
        bool login(const std::string& username, const std::string& password) {
            // Si existe el nombre de usuario dentro de la base de datos
            if (db_->userExists(username)) {
                // Retorna un booleano para indicar si el password coincide con el de la cuenta
                return db_->getPassword(username) == password;
            }
            return false;
        }
        
        // Método para registrar un usuario en la base de datos 
        void registerUser(const std::string& username, const std::string& password) {
            // Si no existe el usuario en la base de datos
            if (!db_->userExists(username)) {
                // Agrega el usuario a la base de datos con su username y password
                db_->addUser(username, password);
            }
        }

    private:
        Database* db_; // Instancia privada de la base de datos
};

#endif // AUTHENTICATION_H