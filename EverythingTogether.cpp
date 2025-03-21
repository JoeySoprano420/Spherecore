int main() {
    std::string code = "If_true New_define x 10 End_if";
    
    Lexer lexer(code);
    std::vector<Token> tokens = lexer.tokenize();
    
    Parser parser(tokens);
    std::vector<std::string> ast = parser.parse();
    
    std::string binaryCode = generateBinary(ast);
    std::cout << "Generated Binary: " << binaryCode << std::endl;

    executeBinary(binaryCode); // AVX2 Optimized Execution
    
    writeAssemblyFile(binaryCode);
    compileToExecutable();
    runExecutable();
    
    return 0;
}
