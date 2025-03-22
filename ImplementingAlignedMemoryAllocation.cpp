void* allocateAlignedMemory(size_t size, size_t alignment) {
    void* ptr;
    posix_memalign(&ptr, alignment, size);
    return ptr;
}
