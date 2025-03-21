int main() {
    std::string code = "New_define x 10";
    
    Lexer lexer(code);
    std::vector<Token> tokens = lexer.tokenize();
    
    Parser parser(tokens);
    std::map<std::string, std::string> ast = parser.parse();
    
    std::string binaryCode = generateBinary(ast);
    std::cout << "Generated Binary: " << binaryCode << std::endl;

    executeBinary(binaryCode);
    
    return 0;
}
