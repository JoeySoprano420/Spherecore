#include <immintrin.h>

void executeBinary(const std::string& binaryCode) {
    int compiledValue = std::stoi(binaryCode, nullptr, 2);
    
    __m256i data = _mm256_set1_epi32(compiledValue);
    __m256i factor = _mm256_set1_epi32(10);
    __m256i result = _mm256_add_epi32(data, factor);

    alignas(32) int output[8];
    _mm256_store_si256((__m256i*)output, result);

    std::cout << "Execution Output: " << output[0] << std::endl;
}
