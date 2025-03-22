#include <iostream>
#include <chrono>

enum DiagnosticLevel { ERROR, WARNING, INFO, PERFORMANCE };

void LogDiagnostic(DiagnosticLevel level, const std::string& message) {
    std::string prefix;
    switch (level) {
        case ERROR: prefix = "[Error]: "; break;
        case WARNING: prefix = "[Warning]: "; break;
        case INFO: prefix = "[Info]: "; break;
        case PERFORMANCE: prefix = "[Performance]: "; break;
    }
    std::cout << prefix << message << std::endl;
}

void MeasurePerformance(std::function<void()> func, const std::string& functionName) {
    auto start = std::chrono::high_resolution_clock::now();
    func();
    auto end = std::chrono::high_resolution_clock::now();
    
    std::chrono::duration<double, std::milli> elapsed = end - start;
    LogDiagnostic(PERFORMANCE, functionName + " executed in " + std::to_string(elapsed.count()) + " ms.");
}

// Example Usage
void TestFunction() {
    for (int i = 0; i < 1000000; ++i);
}

int main() {
    MeasurePerformance(TestFunction, "TestFunction");
    return 0;
}
