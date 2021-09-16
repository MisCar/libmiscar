load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
    name = "bazelrio",
    sha256 = "aa6091ada04f272abd96afa1cfd7ebb3a3ec115268014bebf6082e0ec4bdc946",
    strip_prefix = "bazelrio-add-dependency-update-script/bazelrio",
    url = "https://github.com/noamzaks/bazelrio/archive/refs/heads/add-dependency-update-script.zip",
)

load("@bazelrio//:deps.bzl", "setup_bazelrio_dependencies")

setup_bazelrio_dependencies()

register_toolchains("@bazelrio//toolchains/roborio")

load("@rules_python//python:pip.bzl", "pip_install")

pip_install(
    name = "__bazelrio_deploy_pip_deps",
    requirements = "@bazelrio//deploy:requirements.txt",
)
