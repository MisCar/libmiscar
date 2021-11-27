load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

http_archive(
    name = "bazelrio",
    strip_prefix = "bazelRio-beta/bazelrio",
    url = "https://github.com/noamzaks/bazelrio/archive/refs/heads/beta.zip",
)

load("@bazelrio//:deps.bzl", "setup_bazelrio_dependencies")

setup_bazelrio_dependencies(
    phoenix_version = "5.20.0-beta-1",
    wpilib_version = "2022.1.1-beta-2",
)

load("@bazelrio//:defs.bzl", "setup_bazelrio")

setup_bazelrio()

git_repository(
    name = "gtest",
    branch = "main",
    remote = "https://github.com/google/googletest",
)
