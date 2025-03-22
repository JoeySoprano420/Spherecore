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

enum class TokenType {
    DEFINE_FUNCTION, RETURN, CALL_FUNCTION
};

class Parser {
    std::unordered_map<std::string, std::vector<std::string>> functions;

public:
    void parseFunction(std::vector<Token>& tokens) {
        std::string functionName = tokens[1].value;
        functions[functionName] = {};

        for (size_t i = 2; i < tokens.size(); ++i) {
            if (tokens[i].type == TokenType::END_FUNCTION) break;
            functions[functionName].push_back(tokens[i].value);
        }
    }

    void callFunction(std::string functionName, int arg) {
        if (functions.find(functionName) != functions.end()) {
            executeBinary(generateBinary(functions[functionName]));
        }
    }
};
