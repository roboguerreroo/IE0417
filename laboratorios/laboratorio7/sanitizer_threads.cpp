#include <iostream>
#include <thread> // Make sure to include <thread> for std::thread

int counter = 0;

void increment() {
    for (int i = 0; i < 100000; ++i) {
        ++counter; // Condición de carrera
    }
}

int main() {
    std::thread t1(increment);
    std::thread t2(increment);

    t1.join();
    t2.join();

    std::cout << "Counter: " << counter << std::endl;
    return 0;
}

/*
SANITIZER THREADS  

$ g++ -fsanitize=thread -g -o sanitizer_threads.exe sanitizer_threads.cpp
$ ./sanitizer_threads.exe 

La salida de ThreadSanitizer indica que dos hilos (T1 y T2) están intentando leer y escribir simultáneamente en la misma variable global (counter) sin ninguna protección. Esto significa que las operaciones de incremento (++counter) no son atómicas; un hilo puede leer el valor, otro hilo puede leer el mismo valor antes de que el primero lo actualice, y luego ambos hilos intentan escribir su nuevo valor, causando que una de las actualizaciones se pierda.

Solución típica (aunque TSan no la indica directamente, la detecta):
Para solucionar una condición de carrera como esta, necesitas sincronizar el acceso a counter. Las formas más comunes en C++ son:

Usar un std::mutex para proteger la sección crítica (++counter).
Usar un std::atomic<int> para la variable counter, lo que garantiza que las operaciones sobre ella sean atómicas (indivisibles).
*/

/*
ANALISIS DE HILOS

$ g++ -g -o sanitizer.exe sanitizer_threads.cpp 
$ valgrind --tool=helgrind ./sanitizer.exe 

La salida de Helgrind es una prueba irrefutable de que tu programa tiene una condición de carrera en la variable global counter debido a que múltiples hilos (t1 y t2) intentan incrementarla simultáneamente sin ninguna sincronización (como un std::mutex o std::atomic).

Helgrind te indica exactamente dónde está el problema: la línea 8 de sanitizer_threads.cpp (++counter;), y te muestra cómo los hilos están compitiendo por acceder y modificar esa misma dirección de memoria (0x10c154).

Para solucionar esto, necesitas introducir un mecanismo de sincronización para proteger el acceso a counter.

El programa anterior se corrige agregando un mutex para proteger el acceso a la variable counter:

#include <iostream>
#include <thread>
#include <mutex> // Include <mutex> for std::mutex
#include <atomic> // Include <atomic> for std::atomic
std::mutex mtx; // Mutex to protect access to counter
int counter = 0;
void increment() {
    for (int i = 0; i < 100000; ++i) {
        mtx.lock(); // Lock the mutex before accessing counter
        ++counter; // Increment counter
        mtx.unlock(); // Unlock the mutex after accessing counter
    }
}
int main() {
    std::thread t1(increment);
    std::thread t2(increment);

    t1.join();
    t2.join();

    std::cout << "Counter: " << counter << std::endl;
    return 0;
}

*/