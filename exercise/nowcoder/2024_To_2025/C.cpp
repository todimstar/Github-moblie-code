#include <iostream>  
#include <cstdint>  

int main() {  
    uint64_t numerator = 1;  
    uint64_t denominator = 9999999999999999;  
    uint64_t result = 0;  
    int precision = 1600;  

    for (int i = 0; i < precision; i++) {  
        numerator *= 10;  
        result = numerator / denominator;  
        numerator %= denominator;  
    }  

    std::cout << result << std::endl;  
    return 0;  
}