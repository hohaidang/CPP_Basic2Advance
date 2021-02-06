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

  // play ground, phan nay phai chuyen IMPORT_MESSAGE -> s thanh public
  auto data = msg.s<0, 1>(); // tach char tu phan tu 0 length = 1
  if(data == stringNZ<1>("D")) { // so sanh string
    std::cout << "Equal" << std::endl;
  } else {
    std::cout << "Not Equal" << std::endl;
  }

  auto length = msg.s<0, 4>().parseUInt().asOptional(); // convert string thanh kieu int, va wrap ve 1 cai optional
  std::cout << "length = " << *length << std::endl; // tra ve content
}
