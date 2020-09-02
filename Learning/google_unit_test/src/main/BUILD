load("@rules_cc//cc:defs.bzl", "cc_binary")

cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    deps = ["//src/lib:cpp_lib"]
)

cc_binary(
    name = "main_logger",
    srcs = ["main_logger.cpp"],
    deps = [
        "@glog",
    ],
)