load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

http_archive(
    name = "bazelrio",
    sha256 = "63840300af45a0a4f89e9d3e6728858d103765bda44e3d0ea83e35fb5317cdc7",
    strip_prefix = "bazelRio-0.5.0/bazelrio",
    url = "https://github.com/bazelRio/bazelRio/archive/refs/tags/0.5.0.zip",
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
