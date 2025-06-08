#include <gtest/gtest.h> // Biblioteca para GoogleTest
#include <gmock/gmock.h> // Biblioteca para GoogleMock
#include "authentication.h" 
#include "mock_database.h"

using ::testing::Return;

// Prueba para el inicio de sesión exitoso
TEST(AuthenticationTest, LoginSuccess) {
    MockDatabase db;
    Authentication auth(&db);

    // Se espera un llamado de usuario "Alice" y se indica que existe
    EXPECT_CALL(db, userExists("Alice"))
        .WillOnce(Return(true));
    // Contraseña de usuario "Alice" es "password"
    EXPECT_CALL(db, getPassword("Alice"))
        .WillOnce(Return("password"));
    // Se espera que el resultado sea true si se inicia sesión con el usuario "Alice" y contraseña "password"
    EXPECT_TRUE(auth.login("Alice", "password"));
}

// Prueba para el inicio de sesión fallido
TEST(AuthenticationTest, LoginFailure) {
    MockDatabase db;
    Authentication auth(&db);

    // Usuario "Alice" existe
    EXPECT_CALL(db, userExists("Alice"))
        .WillOnce(Return(true));
    // Contraseña de usuario "Alice" es "password"
    EXPECT_CALL(db, getPassword("Alice"))
        .WillOnce(Return("password"));
    // Se espera que el resultado sea false, si se ingresa usuario "Alice" y contraseña "wrongpassword"
    EXPECT_FALSE(auth.login("Alice", "wrongpassword"));
    
    // Usuario "Bob" no existe
    EXPECT_CALL(db, userExists("Bob"))
        .WillOnce(Return(false));
    // Se espera que el resultado sea false si se ingresa un usuario "Bob" y contraseña "password"
    EXPECT_FALSE(auth.login("Bob", "password"));
}

// Prueba para el registro de un nuevo usuario
TEST(AuthenticationTest, RegisterUser) {
    MockDatabase db;
    Authentication auth(&db);

    // Usuario "Charlie" no existe
    EXPECT_CALL(db, userExists("Charlie"))
        .WillOnce(Return(false));

    // Se espera un llamado de addUser("Charlie", "password") una vez en la ejecución del test
    EXPECT_CALL(db, addUser("Charlie", "password"))
        .Times(1);

    // Ejecución de la función registrar usuario
    auth.registerUser("Charlie", "password");
}

// Función principal para ejecutar los tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    // Ejecutar todos los tests
    return RUN_ALL_TESTS();
}
