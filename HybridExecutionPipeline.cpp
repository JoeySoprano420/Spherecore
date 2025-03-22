void ExecuteHybridPipeline() {
    enableAVX2();
    enableGPU();
    
    auto mainFunc = LoadFunction("MainFunc");
    auto heavyCompute = LoadFunction("HeavyComputation");

    ((void(*)())mainFunc)();  // AOT-compiled execution

    if (isGPUSupported()) {
        ExecuteOnGPU(heavyCompute);
    } else {
        ExecuteOnCPU(heavyCompute);
    }

    debugExecution("Optimized execution complete.");
}
