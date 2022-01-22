load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

http_archive(
    name = "bazelrio",
    sha256 = "eb71b5fcba374f27a0ce2634bd4e8518ad6ae56fb56decfcbdad619bef06e0ad",
    strip_prefix = "bazelRio-0.6.0/bazelrio",
    url = "https://github.com/bazelRio/bazelRio/archive/refs/tags/0.6.0.zip",
)

load("@bazelrio//:deps.bzl", "setup_bazelrio_dependencies")

setup_bazelrio_dependencies()

load("@bazelrio//:defs.bzl", "setup_bazelrio")

setup_bazelrio()

git_repository(
    name = "gtest",
    branch = "main",
    remote = "https://github.com/google/googletest",
)
