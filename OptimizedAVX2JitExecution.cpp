#include <immintrin.h>

void simd_computation(float* data1, float* data2, float* result, int size) {
    for (int i = 0; i < size; i += 8) {
        _mm_prefetch((char*)&data1[i+8], _MM_HINT_T0);
        __m256 va = _mm256_load_ps(&data1[i]);
        __m256 vb = _mm256_load_ps(&data2[i]);
        __m256 vc = _mm256_add_ps(va, vb);
        _mm256_store_ps(&result[i], vc);
    }
}
