class MemoryManager {
    std::unordered_map<std::string, void*> heapAllocations;
    int64_t stackMemory[1024];  
    int stackPointer = 0;  

public:
    void allocate(std::string var, size_t size) {
        heapAllocations[var] = malloc(size);
    }

    void store(std::string var, int value) {
        if (heapAllocations.find(var) != heapAllocations.end()) {
            *(int*)heapAllocations[var] = value;
        }
    }

    void free(std::string var) {
        if (heapAllocations.find(var) != heapAllocations.end()) {
            free(heapAllocations[var]);
            heapAllocations.erase(var);
        }
    }
};
