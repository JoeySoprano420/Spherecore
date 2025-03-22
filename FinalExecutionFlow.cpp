int main() {
    Debugger debugger;
    MemoryManager memory;
    
    std::string code = "Allocate_memory(x, 10) Store_value(x, 42) Free_memory(x)";
    
    Lexer lexer(code);
    std::vector<Token> tokens = lexer.tokenize();
    
    Parser parser(tokens);
    std::vector<std::string> ast = parser.parse();
    
    std::string binaryCode = generateBinary(ast);
    debugger.stepExecution(binaryCode);
    
    executeBinary(binaryCode);
    debugger.inspectMemory("x", memory.heapAllocations["x"]);
    
    executeFunction("factorial", 5);
    
    return 0;
}
