void writeExecutable(std::vector<uint8_t> binary) {
    std::ofstream exeFile("output.exe", std::ios::binary);
    exeFile.write(reinterpret_cast<const char*>(binary.data()), binary.size());
    exeFile.close();
}
