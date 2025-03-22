#include <thread>
#include <vector>

class ThreadManager {
    std::vector<std::thread> threads;

public:
    void startThread(void (*task)()) {
        threads.emplace_back(task);
    }

    void waitForAll() {
        for (auto& t : threads) t.join();
    }
};

void Task1() { /* Compute-heavy function */ }
void Task2() { /* Compute-heavy function */ }

int main() {
    ThreadManager tm;
    tm.startThread(Task1);
    tm.startThread(Task2);
    tm.waitForAll();
}
