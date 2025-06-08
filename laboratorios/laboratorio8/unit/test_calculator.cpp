#include <gtest/gtest.h>
#include "calculator.h"

// Definición de la clase CalculatorTest
class CalculatorTest : public ::testing::Test {
    protected:
        // Instancia de Calculadora
        Calculator calc;
    
    void SetUp() override {
        // Configuración común que se necesita antes de cada test
    }

    void TearDown() override {
        // Limpieza común que se necesita después de cada test
    }
};

// Prueba para el método Add
TEST_F(CalculatorTest, AddTest) {
    EXPECT_EQ(calc.Add(1,1), 2);
    EXPECT_EQ(calc.Add(-1,1), 0);
    EXPECT_EQ(calc.Add(-1,-1), -2);
}

// Prueba para el método Subtract
TEST_F(CalculatorTest, SubtractTest) {
    EXPECT_EQ(calc.Subtract(2, 1), 1);
    EXPECT_EQ(calc.Subtract(-1, 1), -2);
    EXPECT_EQ(calc.Subtract(-1, -1), 0);
}

// Función principal para ejecutar los tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);

    // Ejecutar todos los tests
    return RUN_ALL_TESTS();
}