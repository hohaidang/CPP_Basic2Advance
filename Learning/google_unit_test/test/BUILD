load("@rules_cc//cc:defs.bzl", "cc_test", "cc_binary")

cc_test(
    name = "test_hello",
    srcs = glob(["**/*.cpp"]),
    deps = [
        "//src/lib:cpp_lib",
        "@googletest//:gtest_main",
    ],
)

cc_binary(
	name = "test_fixtures",
	srcs = ["test_fixtures.cpp"],
	deps = [
		"@googletest//:gtest_main",
	],
)

cc_binary(
	name = "test_gmock",
	srcs = ["test_gmock.cpp"],
	deps = [
		"@googletest//:gtest_main",
	],
)
