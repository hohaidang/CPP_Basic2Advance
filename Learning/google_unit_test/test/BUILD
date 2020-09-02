load("@rules_cc//cc:defs.bzl", "cc_test")

cc_test(
    name = "test_hello",
    srcs = glob(["**/*.cpp"]),
    deps = [
        "//src/lib:cpp_lib",
        "@googletest//:gtest_main",
    ],
)