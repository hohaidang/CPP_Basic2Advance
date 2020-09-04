
Building the project
1. The UnitTestForEmbeddedC project was created with VisualStudio 2012.
   Only Debug|Win32 configuration is available.
2. The project is using gmock-1.7.0.
   The gmock framework is not distributed with the project and you will need to download and build it prior to building the project.
   You only need to build gmock project (no need to build gmock_main and gmock_test).
3. If you build gmock with VisualStudio 2012 you will need to add "_VARIADIC_MAX=10" to preprocessor definitons,
   otherwise you will get compilation errors (https://code.google.com/p/googletest/issues/detail?id=412).
4. After building gmock, edit UnitTestForEmbeddedC project settings.
   a. Set compiler "additional include directories" to point to your gmock project location.
   b. Set linker "additional dependecies" to include gmock-all.obj and gtest-all.obj files.

Unit test examples
1. ArrayUnitTest.cpp
   This is example of using Google test for C funtions testing. There are no mocks in the test.

2. QueueUnitTest.cpp
   This is example of unit test for a module that contains mock HOOKs. The test itself does not use mocks.

3. CallingServicesUnitTest.cpp
   This is example of unit test that uses services mocks.

4. CallingModuleWithHooksUnitTest.cpp
   This is example of module mocks usage. The test refers to two mocked modules: Queue and Stub. The last one is dummy.

5. StubUnitTest.cpp
   This is example of dummy test for module that is not part of testing project yet, but other modules depend on it.
