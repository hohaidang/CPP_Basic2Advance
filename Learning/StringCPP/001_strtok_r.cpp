// C program to demonstrate working of strtok_r() 
// by splitting string based on space character. 
#include <stdio.h> 
#include <string.h> 
#include <iostream>

// strtok_r(__s, __delim, __save_ptr)
// __s la str can tach, sau khi tach __s se khong con nguyen ven
// __delim ky tu phan biet de tach
// __save_ptr chuoi str con lai sau khi tach
// return ve chuoi str truoc __delim

int main() 
{ 
    char str[] = "dang dep trai"; 
    std::cout << "str init = " << str << '\n';
    char* token; 
    char* rest = str; 
    token = strtok_r(rest, " ", &rest); // tach chuoi voi dau white space
    std::cout << "str = " << str << '\n';
    std::cout << "rest = " << rest << '\n';
    std::cout << "token = " << token << '\n';
    token = strtok_r(rest, " ", &rest);
    std::cout << "str = " << str << '\n';
    std::cout << "rest = " << rest << '\n';
    std::cout << "token = " << token << '\n';
    return (0); 
} 