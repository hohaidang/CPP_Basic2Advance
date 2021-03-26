// crt_byteswap.c
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <iostream>

int main()
{
  uint64_t u64 = 0x0102030405060708; 
  std::cout << "byteswap of 0x" << std::hex << u64 << " = 0x" << __builtin_bswap64(u64);
}
