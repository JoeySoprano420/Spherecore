#include <vector>
#include <string>

void Debug_Log(const std::string& message) {
    std::cout << "[Debug]: " << message << std::endl;
}

void Debug_Breakpoint() {
    asm volatile("int3");
}

void Debug_TraceCallStack() {
    void* callstack[10];
    int frames = backtrace(callstack, 10);
    char** symbols = backtrace_symbols(callstack, frames);
    
    std::cout << "[Stack Trace]: " << std::endl;
    for (int i = 0; i < frames; i++) {
        std::cout << symbols[i] << std::endl;
    }
    free(symbols);
}
