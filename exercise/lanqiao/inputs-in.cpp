#include <iostream>
#include <fstream>
#include <string>

int main() {
    // 打开文件
    std::ifstream file("19765.in");

    // 检查文件是否成功打开
    if (!file.is_open()) {
        std::cerr << "无法打开文件" << std::endl;
        return 1;
    }

    std::string line;
    // 读取文件，直到文件结束
    while (getline(file, line)) {
        // 打印每一行
        std::cout << line << std::endl;
    }

    // 关闭文件
    file.close();

    return 0;
}