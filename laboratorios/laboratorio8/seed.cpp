// Bibliotecas
#include <iostream>
#include <random>

int main() {
    // Establecer una semilla 
    unsigned int seed = 12345;

    // Utilizar mt19937 para generar números con la semilla especificada
    std::mt19937 generator(seed);

    // Generar 5 números aleatorios
    for (int i=0; i<5; ++i) {
        std::cout << generator() << std::endl;
    }

    return 0;
}