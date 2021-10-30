load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
    name = "bazelrio",
    strip_prefix = "bazelRio-main/bazelrio",
    url = "https://github.com/bazelrio/bazelrio/archive/refs/heads/main.zip",
)

load("@bazelrio//:deps.bzl", "setup_bazelrio_dependencies")

setup_bazelrio_dependencies()

register_toolchains("@bazelrio//toolchains/roborio")

load("@rules_python//python:pip.bzl", "pip_install")

pip_install(
    name = "__bazelrio_deploy_pip_deps",
    requirements = "@bazelrio//deploy:requirements.txt",
)
