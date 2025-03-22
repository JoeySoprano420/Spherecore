int factorial(int x) {
    if (x <= 1) return 1;
    return x * factorial(x - 1);
}

void executeFunction(std::string functionName, int argument) {
    if (functionName == "factorial") {
        std::cout << "Factorial of " << argument << " = " << factorial(argument) << std::endl;
    }
}
