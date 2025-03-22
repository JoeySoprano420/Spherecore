#pragma optimize("gt", on)  // Enable global optimizations

void ComputeFunction(int x) {
    if (x > 10) {
        __builtin_prefetch(&x, 0, 1); // Prefetch memory
    }
    x *= 2;
    x += 5;
}
