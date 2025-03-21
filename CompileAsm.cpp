void compileToExecutable() {
    system("nasm -f win64 output.asm -o output.obj");
    system("gcc output.obj -o output.exe");
    std::cout << "Executable output.exe generated!" << std::endl;
}
