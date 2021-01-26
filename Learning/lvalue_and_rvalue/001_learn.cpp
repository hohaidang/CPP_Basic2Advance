#include <iostream>

// tra ve reference cho bien static
int& GetValue() {
    static int value = 10;
    return value;
}

int GetRvalue() {
    return 10;
}

void SetValue(int &value) {}
void SetConstValue(const int& value) {}

int main() {
    // lvalue la co memory, con rvalue la khong co memory
    // GetValue() va i luc nay deu la lvalue vi deu co memory
    int i = GetValue();
    GetValue() = 5;

    int y = GetRvalue(); // GetRvalue luc nay se la rvalue boi vi no khong co dia chi

    int m = 10;
    SetValue(m);
    //SetValue(10); // cho nay build se loi, boi vi value la reference 
    //khong the assign vao 1 vung khong co dia chi
    SetConstValue(10); // cho nay se OK boi vi compiler se hieu la gan gia tri 10
    // vao cho bien value trong function SetConstValue

}