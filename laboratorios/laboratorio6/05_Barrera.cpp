#include <iostream>
#include <thread>
#include <barrier>
#include <vector>

// std::barrier sync_point(5); // Barrera para 5 hilos
std::barrier sync_point(3, [](){
    std::cout << "Todos los hilos han sincronizado." << std::endl;
});

void threadFunction(int id) {
    // // Realizar tareas antes de la barrera
    std::cout << "Hilo " << id << " realizando trabajo antes de la barrera." << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(100 * id));
    // sync_point.arrive_and_wait(); // // Esperar a que todos los hilos lleguen aquí
    sync_point.arrive_and_wait();
    // // Continuar después de que todos los hilos hayan sincronizado
    std::cout << "Hilo " << id << " pasó la barrera." << std::endl;
}

int main() {
    std::vector<std::thread> threads;
    for (int i = 1; i <= 3; ++i) {
        threads.emplace_back(threadFunction, i);
    }
    for (auto& t : threads) t.join();

    return 0;
}
