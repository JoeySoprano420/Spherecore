enum class TokenType {
    // Existing Tokens...
    IF_TRUE, IF_FALSE, ELSE_CONTINUE, END_IF,
    WHILE_ACTIVE, REPEAT_UNTIL, END_LOOP
};

class Lexer {
public:
    std::vector<Token> tokenize() {
        std::vector<Token> tokens;
        
        while (position < source.length()) {
            std::string identifier;
            while (std::isalnum(source[position])) {
                identifier += source[position++];
            }
            
            if (identifier == "If_true") tokens.push_back({TokenType::IF_TRUE, identifier});
            else if (identifier == "If_false") tokens.push_back({TokenType::IF_FALSE, identifier});
            else if (identifier == "Else_continue") tokens.push_back({TokenType::ELSE_CONTINUE, identifier});
            else if (identifier == "End_if") tokens.push_back({TokenType::END_IF, identifier});
            else if (identifier == "While_active") tokens.push_back({TokenType::WHILE_ACTIVE, identifier});
            else if (identifier == "Repeat_until") tokens.push_back({TokenType::REPEAT_UNTIL, identifier});
            else if (identifier == "End_loop") tokens.push_back({TokenType::END_LOOP, identifier});
            else tokens.push_back({TokenType::IDENTIFIER, identifier});
        }
        
        return tokens;
    }
};
