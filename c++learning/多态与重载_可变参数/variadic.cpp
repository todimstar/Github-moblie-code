#include <iostream> //c++中可变参数用va
#include <cstdarg>

/*C++ 使用 ... 来表示可变参数，不过这种方式比较底层（类似于 C 的 stdarg.h）
需要结合 va_list 来访问可变参数。也可以使用 C++11 中的模板参数包实现更灵活的可变参数。*/

void display(int count, ...) {//传统va方法
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; ++i) {
        std::cout << va_arg(args, int) << " ";
    }
    va_end(args);
    std::cout << std::endl;
}

int main() {
    display(3, 1, 2, 3);  // 传递三个参数
    display(1, 10);       // 传递一个参数
    return 0;
}
