package(default_visibility = ["//visibility:public"])

load("@rules_cc//cc:defs.bzl", "cc_binary")

cc_binary(
    name = "gdb",
    srcs = ["gdb.cc"],
    copts = [
        "-std=c++17",
        "-g",
    ],
)
