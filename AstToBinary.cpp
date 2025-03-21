std::string generateBinary(const std::vector<std::string>& ast) {
    std::string binaryCode;
    
    for (const std::string& node : ast) {
        if (node == "IF_CONDITION_START") binaryCode += "0001"; 
        else if (node == "ELSE_BRANCH") binaryCode += "0010";
        else if (node == "IF_CONDITION_END") binaryCode += "0011";
        else if (node == "WHILE_LOOP_START") binaryCode += "0100";
        else if (node == "WHILE_LOOP_END") binaryCode += "0101";
        else binaryCode += "1100"; // Default operation code
    }

    return binaryCode;
}
