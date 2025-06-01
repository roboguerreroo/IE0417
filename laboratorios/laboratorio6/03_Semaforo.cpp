#include <iostream>
#include <thread>
#include <semaphore>
#include <chrono>

// std::counting_semaphore<1> sem(1); // Semáforo binario (similar a un mutex)
std::counting_semaphore<1> sem(1);

void accessResource() {
    sem.acquire(); // // Decrementa el contador y bloquea si el contador es cero
    // // Sección crítica
    std::cout << "Accediendo a recurso crítico" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1)); // Simular trabajo
    sem.release(); // // Incrementa el contador y desbloquea a un hilo bloqueado
}

int main() {
    std::thread t1(accessResource);
    std::thread t2(accessResource);

    t1.join();
    t2.join();

    return 0;
}
