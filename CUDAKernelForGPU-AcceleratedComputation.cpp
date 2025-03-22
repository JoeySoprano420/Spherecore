__global__ void gpu_compute(float* data, int size) {
    int i = blockIdx.x * blockDim.x + threadIdx.x;
    if (i < size) {
        data[i] = data[i] * 2.0f + 5.0f;  // Fast parallel computation
    }
}

void ExecuteOnGPU(float* data, int size) {
    float* d_data;
    cudaMalloc(&d_data, size * sizeof(float));
    cudaMemcpy(d_data, data, size * sizeof(float), cudaMemcpyHostToDevice);

    int blockSize = 256;
    int numBlocks = (size + blockSize - 1) / blockSize;
    gpu_compute<<<numBlocks, blockSize>>>(d_data, size);

    cudaMemcpy(data, d_data, size * sizeof(float), cudaMemcpyDeviceToHost);
    cudaFree(d_data);
}
