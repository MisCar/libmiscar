load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
    name = "bazelrio",
    strip_prefix = "bazelRio-main/bazelrio",
    url = "https://github.com/bazelrio/bazelrio/archive/refs/heads/main.zip",
)

load("@bazelrio//:deps.bzl", "setup_bazelrio_dependencies")

setup_bazelrio_dependencies(
    phoenix_version = "5.20.0-beta-1",
    wpilib_version = "2022.1.1-beta-2",
)

register_toolchains("@bazelrio//toolchains/roborio")

load("@rules_python//python:pip.bzl", "pip_install")

pip_install(
    name = "__bazelrio_deploy_pip_deps",
    requirements = "@bazelrio//deploy:requirements.txt",
)
