cc_binary(
    name = "hello-world",
    srcs = ["hello-world.cpp"],
	defines = ["FLAG"],	
	deps = [
		":hello-greet",
	],
)

cc_library(
	name = "hello-greet",
	srcs = ["hello-greet.cpp"],
	hdrs = ["hello-greet.h"],
	deps = ["hello-lib"],
)

cc_library(
	name = "hello-lib",
	srcs = ["hello-lib.cpp"],
	hdrs = ["hello-lib.h" , "def.h"]
)