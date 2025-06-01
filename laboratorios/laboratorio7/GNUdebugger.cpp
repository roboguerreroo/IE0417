#include <iostream>

void funcion1() {
    int a = 5;
    int b = 3;
    int c = a / b; // Error: División por cero
    std::cout << "Resultado: " << c << std::endl;
}

int main() {
    std::cout << "Iniciando el programa" << std::endl;
    funcion1();
    std::cout << "Finalizando el programa" << std::endl;
    return 0;
}

/*
> g++ -g -o programa programa.cpp 
> gdb programa            #Preparar el programa para la depuración.
> (gdb) run               #Iniciar una sesión de depuración.
> (gdb) break funcion1    #Ejecutar el programa.
> (gdb) continue          #Establecer puntos de interrupción para pausar la ejecución en puntos específicos.
> (gdb) next              #Avanzar línea por línea (next o step).
> (gdb) print a           #Inspeccionar los valores de las variables (print).
> (gdb) step              #Inspeccionar los valores de las variables (print).
> (gdb) backtrace         #Comprender la secuencia de llamadas a funciones (backtrace).
> (gdb) continue          #Reanudar la ejecución.
*/
