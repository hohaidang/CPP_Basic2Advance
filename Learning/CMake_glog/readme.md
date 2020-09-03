# Project is used to glog as a static library. Then create a new source file main.cpp and link to static glog library

Tested on Ubuntu 18.04 and Windows 10

Reference https://github.com/google/glog/blob/master/cmake/INSTALL.md

$ git clone https://github.com/google/glog

$ cd glog

$ cmake .

$ make

$ make install // cai nay (optionnal), khi chay make install thi no se copy static library va header vao thu muc usr/local/include

$ cd .. // go back to CMake_glog folder

$ cmake . // link main.cpp file to glog static library

Linux:

$ make // create application for main

Windows:

Open file .sln using visual studio. -> BUILD ALL
