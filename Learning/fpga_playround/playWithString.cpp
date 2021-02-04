#include "../common/TestUtils.hpp"
#include "top.hpp"
#include <iostream>

hls::stream<ap_uint<256>> tcp_msg;

int main() {
  // initialze
  char str[] = {"1234"};
  ap_uint<256> _buffer[1] = 0;
  memcpy(&_buffer[0], str, 4);
  std::cout << std::hex << _buffer[0] << std::endl;
  auto buffer = array<1>(_buffer);
  auto a = buffer.map([](typename Raptor::TRXData d) {
    return arrayFromConstUInt<Raptor::trxDataSize, 8>(d);
  }).concat();

  auto msg = Raptor::MxEMAPIMsg<Raptor::Message<decltype(a)>>(a);

  // play ground
  auto data = msg.s<0, 1>(); // tach char tu phan tu 0 length = 1
  if(data == stringNZ<1>("D")) { // so sanh string
    std::cout << "Equal" << std::endl;
  } else {
    std::cout << "Not Equal" << std::endl;
  }

  auto dang = stringNZ<13>("Dang dep trai"); // khai bao bien
  StringN<15> issueCode = dang; // assign vao StringN
  std::cout << "issueCode = " << issueCode << '\n';
  std::cout << "dang.length = " << dang.length() << '\n';
  std::cout << "dang after change = " << dang << '\n';
  std::cout << "dang[0:5] = " << dang.sub<0, 5>() << '\n';
  dang.prettyPrint(std::cout); std::cout << '\n';

  auto temp3 = StringZArray<1, 7, 'A'>("vuighe"); // A la ky tu duoc gan vao padding. trong truong hop truy suat du lieu ngoai vung nho khai bao
  std::cout << "Before temp3 = " << temp3.s << '\n';
  std::cout << "After temp3 = " << temp3[0] << '\n';

}
