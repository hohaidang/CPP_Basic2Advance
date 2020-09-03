# Project nay la cach build glog lam library. sau do tao mot source file la main.cpp link den thu vien hien tai

# Project nay dat test len Linux va Window

Tham khao https://github.com/google/glog/blob/master/cmake/INSTALL.md

$ git clone https://github.com/google/glog

$ cd glog

$ cmake .

$ make

$ make install // cai nay (optionnal), khi chay make install thi no se copy static library va header vao thu muc usr/local/include

$ cd .. // ra ngoai thu muc CMake_glog

$ cmake . // luc nay se link file main.cpp voi lai library glog moi build o buoc tren

Linux:

$ make // sau buoc nay se tao ra file main. luc nay co the dung de chay

Windows:

Mo file .sln, dung visual studio build.