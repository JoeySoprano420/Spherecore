class Debugger {
    bool enabled = false;
public:
    void setBreakpoint(int line) {
        std::cout << "[DEBUG] Breakpoint set at line: " << line << std::endl;
    }

    void stepExecution(std::string instruction) {
        if (enabled) std::cout << "[DEBUG] Executing: " << instruction << std::endl;
    }

    void inspectMemory(std::string var, void* address) {
        std::cout << "[DEBUG] Variable: " << var << " -> Memory Address: " << address << std::endl;
    }

    void enable() { enabled = true; }
};
