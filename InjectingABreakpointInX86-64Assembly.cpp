void InjectBreakpoint() {
    asm volatile ("int3"); // Triggers a breakpoint
}
