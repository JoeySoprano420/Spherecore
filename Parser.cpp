#include <map>

class Parser {
private:
    std::vector<Token> tokens;
    size_t position;

public:
    Parser(const std::vector<Token>& tokenList) : tokens(tokenList), position(0) {}

    std::map<std::string, std::string> parse() {
        std::map<std::string, std::string> ast;

        while (position < tokens.size() && tokens[position].type != TokenType::END) {
            Token current = tokens[position++];
            
            if (current.type == TokenType::NEW_DEFINE) {
                std::string varName = tokens[position++].value;
                std::string value = tokens[position++].value;
                ast[varName] = value;
            }
        }

        return ast;
    }
};
