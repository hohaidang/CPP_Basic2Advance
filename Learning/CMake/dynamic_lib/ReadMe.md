# Project nay dung de tao dll lib va dung cmake de link lai voi nhau

## Cach tao .dll bang mingw tren window

tao ra .dll

$ g++ -fPIC --shared -o shared.dll shared.cpp

link dll lai voi ham main

$ g++ -L. -lshared -o main main.cpp


Using visual studio compiler

$ cmake . -G "NMake Makefiles"

$ cmake --build . --target ALL_BUILD --config Release

Using gcc compiler

$ cmake . -G "Unix Makefiles"

$ make