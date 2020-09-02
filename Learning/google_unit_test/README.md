Envirionment:

Windows, Linux, MacOS

bazel install

build:

bazel run src/main:main

test:

bazel test test:test_hello

Explanation:
WORKSPACE file: this is a file use to declare all the third party package, it will be downloaded at first when the project running
The bazel command should run in WORKSPACE file's folder
BUILD file: this file just like a makefile, it will declare all of information for building, header files, sources file, dependencies