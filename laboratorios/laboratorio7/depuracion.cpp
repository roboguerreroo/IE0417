#include <iostream>

int main() {
    // Error de sintaxis: falta un punto y coma
    std::cout << "Iniciando el programa" << std::endl;

    int divisor = 2;
    // Error de tiempo de ejecución: división por cero
    int resultado = 10 / divisor;

    int arreglo[5] = {1, 2, 3, 4, 5};
    int suma = 0;
    // Error lógico: la condición del bucle debería ser i < 5
    for (int i = 0; i <= 5; ++i) {
        suma += arreglo[i];
    }

    std::cout << "Suma de los elementos del arreglo: " << suma << std::endl;

    return 0;
}

/* 
BENEFICIONS DE LA DEPURACIÓN EN C++

1. Identificación y Corrección de Errores: Permite encontrar y solucionar fallos (bugs) 
   en el código, desde errores simples de sintaxis hasta problemas lógicos complejos que no 
   son evidentes a primera vista.

2. Mejora de la Calidad del Código: Facilita la escritura de código más limpio y eficiente,

3. Optimización del Rendimiento: Ayuda a identificar cuellos de botella y áreas donde el

4. Comprensión del Comportamiento del Programa: Permite a los desarrolladores entender cómo

5. Confianza en el Software: Un software bien depurado inspira confianza en los usuarios y 
   en los propios desarrolladores, sabiendo que el producto es estable y funciona como se 
   espera.
*/