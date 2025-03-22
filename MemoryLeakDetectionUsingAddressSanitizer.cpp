#include <sanitizer/asan_interface.h>

void CheckMemory() {
    int *ptr = new int[10];
    delete[] ptr;
    
    if (__asan_address_is_poisoned(ptr)) {
        std::cout << "[Memory Error]: Use-after-free detected!" << std::endl;
    }
}
