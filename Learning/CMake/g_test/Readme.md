reference: https://www.youtube.com/watch?v=Lp1ifh9TuFI

configure: create vs-build folder and download googletest and create make file into it 

$ cmake --no-warn-unused-cli -DCMAKE_EXPORT_COMPILE_COMMANDS:BOOL=TRUE -Bbuild

CmakeCache.txt change from "OFF" to "ON"

gtest_force_shared_crt:BOOL=ON

build:

$ cmake --build build --config Debug --target ALL_BUILD -- /maxcpucount:10

clean:

$ cmake --build build --config Debug --target clean --

