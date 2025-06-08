#ifndef MOCK_DATABASE_H
#define MOCK_DATABASE_H

#include <gmock/gmock.h> // Biblioteca para gmock
#include "database.h"    // Declaración de clase Database

// Definición de clase MockDatabase. Hereda de Database
class MockDatabase : public Database {
    public:
        // Mock method para simular userExists
        MOCK_METHOD(bool, userExists, (const std::string& username), (override));

        // Mock method para simular getPassword
        MOCK_METHOD(std::string, getPassword, (const std::string& username), (override));

        // Mock method para simular addUser
        MOCK_METHOD(void, addUser, (const std::string& username, const std::string& password), (override));
};

#endif