#include <vector>

int main() {
    int counter = 0; // inicializar counter

    for (int i = 0; i < 1000; ++i) {
        ++counter; // Incremento no atómico
    }

    std::vector<int> myList;
    // Hilo 1
    myList.push_back(1);
    // Hilo 2
    myList.push_back(2);

    return 0;
}