void executeBinary(const std::string& binaryCode) {
    int compiledValue = std::stoi(binaryCode, nullptr, 2);

    __asm {
        mov eax, compiledValue
        add eax, 10    // Example operation
        mov compiledValue, eax
    }

    std::cout << "Execution Output: " << compiledValue << std::endl;
}
