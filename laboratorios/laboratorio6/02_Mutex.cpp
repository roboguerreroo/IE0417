#include <iostream>
#include <thread>
#include <mutex>

// std::mutex mtx;
std::mutex mtx;

int counter = 0;

// void safeIncrement(int &counter) {
void safeIncrement() {
    // std::lock_guard<std::mutex> lock(mtx);
    std::lock_guard<std::mutex> lock(mtx);
    ++counter;
    // //mtx se libera automáticamente cuando lock sale del ámbito
    std::cout << "Counter: " << counter << std::endl;
}

int main() {
    std::thread t1(safeIncrement);
    std::thread t2(safeIncrement);

    t1.join();
    t2.join();

    return 0;
}
