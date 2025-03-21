class Parser {
public:
    std::vector<std::string> parse() {
        std::vector<std::string> ast;

        while (position < tokens.size()) {
            Token current = tokens[position++];
            
            if (current.type == TokenType::IF_TRUE) {
                ast.push_back("IF_CONDITION_START");
            } else if (current.type == TokenType::ELSE_CONTINUE) {
                ast.push_back("ELSE_BRANCH");
            } else if (current.type == TokenType::END_IF) {
                ast.push_back("IF_CONDITION_END");
            } else if (current.type == TokenType::WHILE_ACTIVE) {
                ast.push_back("WHILE_LOOP_START");
            } else if (current.type == TokenType::END_LOOP) {
                ast.push_back("WHILE_LOOP_END");
            } else {
                ast.push_back(current.value);
            }
        }

        return ast;
    }
};
