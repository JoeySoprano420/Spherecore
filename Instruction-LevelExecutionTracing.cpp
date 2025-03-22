#include <iostream>
#include <vector>

struct Instruction {
    std::string opcode;
    int operand;
};

void TraceExecution(std::vector<Instruction> program) {
    for (const auto& inst : program) {
        std::cout << "[Executing] " << inst.opcode << " " << inst.operand << std::endl;
    }
}

int main() {
    std::vector<Instruction> program = { {"LOAD", 10}, {"ADD", 5}, {"STORE", 0} };
    TraceExecution(program);
    return 0;
}
