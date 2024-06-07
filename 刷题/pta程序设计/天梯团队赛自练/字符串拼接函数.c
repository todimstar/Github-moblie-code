#include <stdio.h>
#include <string.h>
 
void custom_strcat(char *dest, const char *src) {
    while (*dest != '\0') {
        dest++;
    }
 
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
 
    *dest = '\0'; // 添加字符串终止符
}
 
int main() {
    char dest[50] = "Hello, ";
    char src[] = "World!";
    char* p=&dest[3];
    strcat(dest,src);
	printf("strcated string: %s\n", dest);
	printf("strcated后src: %s\n", src);
	printf("p=&dest[3]: %s\n", p);
    
    custom_strcat(dest, src);
 
    printf("Concatenated string: %s\n", dest);
    printf("custom_strcat后src: %s\n", src);
    printf("p=&dest[3]: %s\n", p);
    *(p+3)='\0';
	strcat(dest,src);
    printf("p=&dest[3]: %s\n", p);
    custom_strcat(dest, src);
    printf("p=&dest[3]: %s\n", p);
 
    return 0;
}
