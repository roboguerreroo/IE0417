#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

// std::mutex mtx;
std::mutex mtx;
// std::condition_variable cv;
std::condition_variable cv;
bool ready = false;

void waitingThread() {
    // std::unique_lock<std::mutex> lock(mtx);
    std::unique_lock<std::mutex> lock(mtx);
    // cv.wait(lock, []{ return ready; });
    cv.wait(lock, []{ return ready; }); // // Espera hasta que 'ready' sea true
    // // Continuar ejecución
    std::cout << "Continuar ejecución tras notificación." << std::endl;
}

void notifyingThread() {
    // std::lock_guard<std::mutex> lock(mtx);
    std::lock_guard<std::mutex> lock(mtx);
    ready = true;
    // cv.notify_one(); // // Notifica a uno de los hilos en espera
    cv.notify_one();
}

int main() {
    std::thread t1(waitingThread);
    std::thread t2(notifyingThread);

    t1.join();
    t2.join();

    return 0;
}
