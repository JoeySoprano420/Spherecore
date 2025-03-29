# Minimum required version of CMake
cmake_minimum_required(VERSION 3.20)

# Project details
project(SpherecoreCompiler VERSION 1.0 LANGUAGES CXX ASM)

# Compiler flags and optimizations
set(CMAKE_CXX_STANDARD 20)  # Use C++20 standard
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -march=znver2 -mtune=znver2 -ffast-math -flto -mavx2 -fopenmp")
set(CMAKE_CXX_FLAGS_DEBUG "-g -Wall -Wextra -fsanitize=address,undefined -fstack-protector-all")

# Enable AVX2 for Ryzen optimization
add_compile_options(-mavx2 -mfma -mf16c -m64 -mno-omit-leaf-frame-pointer)

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/include)

# Output directory for build files
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

# Source files for the Spherecore project
file(GLOB_RECURSE SPHERECORE_SRC
    "${PROJECT_SOURCE_DIR}/src/*.cpp"
    "${PROJECT_SOURCE_DIR}/src/*.h"
    "${PROJECT_SOURCE_DIR}/src/*.asm"
)

# Add Spherecore executable
add_executable(SpherecoreCompiler ${SPHERECORE_SRC})

# Link libraries
find_package(Threads REQUIRED)  # For multi-threading
find_package(OpenMP REQUIRED)   # OpenMP for parallelism

if(OpenMP_CXX_FOUND)
    target_link_libraries(SpherecoreCompiler PUBLIC OpenMP::OpenMP_CXX)
endif()

# Optional dependencies: LLVM for JIT and GPU support
find_package(LLVM REQUIRED CONFIG)
if(LLVM_FOUND)
    message(STATUS "LLVM version: ${LLVM_VERSION}")
    include_directories(${LLVM_INCLUDE_DIRS})
    add_definitions(${LLVM_DEFINITIONS})
    target_link_libraries(SpherecoreCompiler PUBLIC LLVM)
endif()

# Link additional libraries
target_link_libraries(SpherecoreCompiler PRIVATE Threads::Threads)

# Debugging hooks and real-time execution tracing
target_compile_definitions(SpherecoreCompiler PRIVATE ENABLE_DEBUG_HOOKS)

# Enable GPU acceleration using CUDA if available
find_package(CUDA REQUIRED)
if(CUDA_FOUND)
    enable_language(CUDA)
    set(CUDA_NVCC_FLAGS ${CUDA_NVCC_FLAGS} -O3 -lineinfo --ptxas-options=-v)
    target_sources(SpherecoreCompiler PRIVATE ${PROJECT_SOURCE_DIR}/src/spherecore_gpu.cu)
    target_link_libraries(SpherecoreCompiler PRIVATE CUDA::cudart)
endif()

# Output binary name for the final compiler
set_target_properties(SpherecoreCompiler PROPERTIES OUTPUT_NAME "spherecore")

# Install target (optional)
install(TARGETS SpherecoreCompiler RUNTIME DESTINATION bin)

# Unit testing setup (if needed)
enable_testing()
add_subdirectory(tests)
