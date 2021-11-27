cc_library(
    name = "miscar",
    srcs = glob([
        "src/main/cpp/miscar/**/*.cpp",
        "src/main/cpp/miscar/**/*.h",
    ]),
    hdrs = glob(["src/main/cpp/**/*.h"]),
    includes = ["src/main/cpp"],
    strip_include_prefix = "src/main/cpp",
    visibility = ["//visibility:public"],
    deps = [
        "@bazelrio//libraries/cpp/ctre/phoenix",
        "@bazelrio//libraries/cpp/rev/revlib",
        "@bazelrio//libraries/cpp/wpilib/new_commands",
        "@bazelrio//libraries/cpp/wpilib/wpilibc",
    ],
)

cc_test(
    name = "miscar.test",
    srcs = glob(["test/cpp/**/*.cpp"]),
    deps = [
        ":miscar",
        "@gtest",
    ],
)
