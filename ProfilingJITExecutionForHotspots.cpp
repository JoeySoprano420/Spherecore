std::unordered_map<std::string, int> executionCount;

void profileFunction(std::string funcName) {
    executionCount[funcName]++;
    if (executionCount[funcName] > HOTSPOT_THRESHOLD) {
        Compile_JIT(funcName);
    }
}
