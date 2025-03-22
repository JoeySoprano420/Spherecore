#include <immintrin.h>

void simd_add(float* a, float* b, float* result, int length) {
    for (int i = 0; i < length; i += 8) {
        __m256 va = _mm256_loadu_ps(&a[i]);
        __m256 vb = _mm256_loadu_ps(&b[i]);
        __m256 vc = _mm256_add_ps(va, vb);
        _mm256_storeu_ps(&result[i], vc);
    }
}
