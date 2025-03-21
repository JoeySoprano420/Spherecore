void writeAssemblyFile(const std::string& binaryCode) {
    std::ofstream asmFile("output.asm");
    asmFile << "section .text" << std::endl;
    asmFile << "global _start" << std::endl;
    asmFile << "_start:" << std::endl;

    for (char bit : binaryCode) {
        if (bit == '1') asmFile << "    add eax, 1" << std::endl;
        else asmFile << "    sub eax, 1" << std::endl;
    }

    asmFile << "    mov eax, 60" << std::endl;
    asmFile << "    xor edi, edi" << std::endl;
    asmFile << "    syscall" << std::endl;
    
    asmFile.close();
}
