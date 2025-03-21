#include <bitset>

std::string generateBinary(const std::map<std::string, std::string>& ast) {
    std::string binaryCode;
    
    for (const auto& entry : ast) {
        binaryCode += std::bitset<16>(std::stoi(entry.second)).to_string();
    }
    
    return binaryCode;
}
