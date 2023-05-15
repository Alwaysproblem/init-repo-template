load("@rules_cc//cc:defs.bzl", "cc_test")

cc_test(
    name = "all_tests",
    srcs = ["main.cpp"],
    deps = [
        "//src/division:division",
        "@com_google_googletest//:gtest_main",
    ],
)
