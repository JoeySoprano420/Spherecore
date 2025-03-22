#version 450
layout(local_size_x = 256) in;

layout(std430, binding = 0) buffer Data {
    float data[];
};

void main() {
    uint i = gl_GlobalInvocationID.x;
    data[i] = data[i] * 2.0 + 5.0;
}
