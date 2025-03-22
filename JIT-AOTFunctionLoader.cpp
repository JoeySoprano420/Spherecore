void* LoadFunction(std::string funcName) {
    if (isJITOptimized(funcName)) {
        return JIT_CompileFunction(funcName);
    } else {
        return AOT_LoadFunction(funcName);
    }
}
