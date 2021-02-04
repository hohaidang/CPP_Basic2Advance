#include <stdio.h>
#include <iostream>
#include <cstring>

int main() {
    char s[] = "geeksforgeeks";
    char buffer[50];
    int j = snprintf(buffer, 13, "dang = %s", s); 
    // 13 la so luong max byte dung trong buffer
    // "dang = %s" la tinh tong so byte luon ca dang va s, toi da duoc 13 ky tu
    std::cout << "s length = " << strlen(s) << '\n';
    printf("string: \n%s\ncharacter count = %d\n", buffer, j);
    // printf("%c", buffer[0]);
    return 0;
}