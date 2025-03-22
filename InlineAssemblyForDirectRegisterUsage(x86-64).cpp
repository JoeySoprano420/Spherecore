void FastMultiply(int* a, int b) {
    asm volatile(
        "imul %1, %0"
        : "=r" (*a)
        : "r" (b), "0" (*a)
    );
}
