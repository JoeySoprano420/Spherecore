void generateBinary(std::vector<std::string> instructions) {
    std::ofstream binaryFile("output.bin", std::ios::binary);

    for (const auto& instr : instructions) {
        uint8_t opcode = encodeInstruction(instr);
        binaryFile.write(reinterpret_cast<const char*>(&opcode), sizeof(opcode));
    }

    binaryFile.close();
}
