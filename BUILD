cc_library(
    name = "miscar",
    srcs = glob(["src/main/cpp/miscar/**/*.cpp"]),
    hdrs = glob(["src/main/cpp/**/*.h"]),
    includes = ["src/main/cpp"],
    strip_include_prefix = "src/main/cpp",
    visibility = ["//visibility:public"],
    deps = [
        "@bazelrio//libraries/ctre/phoenix",
        "@bazelrio//libraries/rev/sparkmax",
        "@bazelrio//libraries/wpilib/commands",
        "@bazelrio//libraries/wpilibc",
    ],
)
