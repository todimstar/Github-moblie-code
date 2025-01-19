#include <iostream>
int main() {
    const char* s = R"(#include <iostream>
int main() {
    const char* s = R"(%s";
    printf(s, s);
    return 0;
})";
    printf(s, s);
    return 0;
}