/*
int* p = new int[10];
// No se libera la memoria asignada

int* p = new int[10];
std::cout << p[0]; // p[0] no está inicializado
delete[] p;

int array[10];
array[10] = 5; // Acceso fuera de los límites del array
*/

#include <iostream>

int main() {
    int* p = new int[10];
    // Aquí se usar la memoria apuntada por 'p', por ejemplo:
    for (int i = 0; i < 10; ++i) {
        p[i] = i * 10;
    }
    std::cout << "Elemento p[0]: " << p[4] << std::endl;

    // Se libera la memoria asignada para evitar la fuga
    delete[] p;
    p = nullptr; // Buena práctica: apunta el puntero a nullptr después de liberar para evitar "dangling pointers"
    return 0;
}

/*
ERRORES DEL CÓDIGO DE MEMORIA EN C++

-se asigna memoria dinámica sin liberarla, lo que causa una fuga de memoria.

-se accede a un elemento no inicializado del array dinámico, lo que puede llevar 
 a resultados inesperados o errores de ejecución.

-se accede a un índice fuera de los límites del array, lo que puede causar un comportamiento indefinido.

*/