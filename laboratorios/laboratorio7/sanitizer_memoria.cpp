#include <iostream>

void funcion1() {
    int* p = new int[10];
    p[10] = 5; // Acceso fuera de los límites del array
    delete[] p;

    int* q = new int[10];
    delete[] q;
    std::cout << q[0] << std::endl; // Uso después de liberar memoria
}

int main() {
    funcion1();
    return 0;
}

/*
SANITARIZER EN C++

Sanitizer es una herramienta de depuración que ayuda a detectar errores comunes en el 
código, como fugas de memoria, accesos a memoria no inicializada, y violaciones de límites
de arrays. En C++, se pueden utilizar diferentes tipos de sanitizers, como AddressSanitizer
(ASan), MemorySanitizer (MSan), ThreadSanitizer (TSan), entre otros.

Se utiliza con el siguiente comando:
$ g++ -fsanitize=address -g -o sanitizer.exe sanitizer_memoria.cpp
$ ./sanitizer.exe 

==26983==ERROR: AddressSanitizer: heap-buffer-overflow on address 0x604000000038 at pc 0x561b4b250342 bp 0x7ffe25f58850 sp 0x7ffe25f58840

==26983==: Es el ID del proceso (PID) que está reportando el error.
ERROR: AddressSanitizer: heap-buffer-overflow: Este es el tipo de error. heap-buffer-overflow significa que tu programa intentó escribir o leer más allá de los límites de un bloque de memoria asignado en el heap.
on address 0x604000000038: Esta es la dirección de memoria exacta donde ocurrió el acceso inválido.
at pc 0x... bp 0x... sp 0x...: Son los valores del Program Counter (PC), Base Pointer (BP) y Stack Pointer (SP) en el momento del error. Útiles para depuración de bajo nivel.

WRITE of size 4 at 0x604000000038 thread T0

WRITE of size 4: Indica que el error fue causado por un intento de escritura de 4 bytes (que es el tamaño de un int en la mayoría de los sistemas) en la dirección especificada.
thread T0: El error ocurrió en el hilo principal del programa.

Estas son algunas de las salidas que podrías ver al ejecutar un programa con 
AddressSanitizer y que indican los errores detectados de manera clara.
*/