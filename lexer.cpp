#include <iostream>
#include <vector>
#include <cctype>
#include <string>

enum class TokenType {
    STRUCT_DEFINE, MAX_GATE_PROSPECT, MAX_EQUIP, MAX_ABLE,
    OPEN_DEFINE, CLOSED_DEFINE, NEW_DEFINE, NEW_VAL, COMMIT_TABLE,
    SEQUENCE_COUNT, IDENTIFIER, NUMBER, OPERATOR, END
};

struct Token {
    TokenType type;
    std::string value;
};

class Lexer {
private:
    std::string source;
    size_t position;
    
public:
    Lexer(const std::string& src) : source(src), position(0) {}

    std::vector<Token> tokenize() {
        std::vector<Token> tokens;
        
        while (position < source.length()) {
            char current = source[position];
            
            if (std::isspace(current)) {
                position++;
                continue;
            }
            
            if (std::isalpha(current)) {  
                std::string identifier;
                while (std::isalnum(source[position])) {
                    identifier += source[position++];
                }
                
                if (identifier == "Struct_define") tokens.push_back({TokenType::STRUCT_DEFINE, identifier});
                else if (identifier == "Max_gate_prospect") tokens.push_back({TokenType::MAX_GATE_PROSPECT, identifier});
                else if (identifier == "Max_equip") tokens.push_back({TokenType::MAX_EQUIP, identifier});
                else if (identifier == "Max_able") tokens.push_back({TokenType::MAX_ABLE, identifier});
                else if (identifier == "Open_define") tokens.push_back({TokenType::OPEN_DEFINE, identifier});
                else if (identifier == "Closed_define") tokens.push_back({TokenType::CLOSED_DEFINE, identifier});
                else if (identifier == "New_define") tokens.push_back({TokenType::NEW_DEFINE, identifier});
                else if (identifier == "New_val") tokens.push_back({TokenType::NEW_VAL, identifier});
                else if (identifier == "Commit_table") tokens.push_back({TokenType::COMMIT_TABLE, identifier});
                else if (identifier == "Sequence_count") tokens.push_back({TokenType::SEQUENCE_COUNT, identifier});
                else tokens.push_back({TokenType::IDENTIFIER, identifier});
                
                continue;
            }
            
            if (std::isdigit(current)) {
                std::string number;
                while (std::isdigit(source[position])) {
                    number += source[position++];
                }
                tokens.push_back({TokenType::NUMBER, number});
                continue;
            }
            
            position++;
        }
        
        tokens.push_back({TokenType::END, ""});
        return tokens;
    }
};
