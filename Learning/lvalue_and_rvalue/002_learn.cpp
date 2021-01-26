#include <iostream>

// chi chap nhan lvalue
void PrintName_lvalue(std::string &s) {
    std::cout << s << '\n';
}

// chi chap nhan rvalue
void PrintName_rvalue(std::string &&s) {
    std::cout << s << '\n';
}

// chap nhan ca rvalue va lvalue
void PrintName_const(const std::string &s) {
    std::cout << s << "\n";
}

int main() {
    std::string firstName = "Ho";
    std::string lastName = " Hai Dang";

    std::string fullName = firstName + lastName;
    // firstName, lastName va fullName la lvalue
    // "Ho", "Dang", va fisrtName + lastName la rvalue
    // boi vi firstName + lastName se la operator+ va tra ve 1 bien 
    //string moi khong co dia chi

    PrintName_lvalue(fullName);
    //PrintName_lvalue(firstName + lastName); // ham nay se bi loi
    // boi vi &s la reference ma fName + lName khong co dia chi

    //PrintName_rvalue(fullName); // ham nay se bi loi
    // boi vi &&s chi chap nhan input la rvalue
    PrintName_rvalue(firstName + lastName);

    // ham nay se chap nhan ca 2, trong truong hop la rvalue compiler se hieu la
    // gan rvalue fName + lName vao bien const &s
    PrintName_const(fullName);
    PrintName_const(firstName + lastName);

    // tai sao &&r_reference lai quan trong, boi vi neu 1 bien chuyen vao la r_value
    // chung ta co the lay owner hoac lam bat cu thu gi len bien do
    // vi dau sao thi sau function do, bien do cung se bi xoa di.
    // dieu nay dan den move_semantic.
}