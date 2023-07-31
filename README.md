# Cpp bazel template

## Env

- install `bazel`

## Generate Compilation database of the whole project

- [bazel-compilation-database](https://github.com/grailbio/bazel-compilation-database#how-to-use)

  ```bash
  INSTALL_DIR="/usr/local/bin"
  VERSION="0.5.2"

  # Download and symlink.
  (
    cd "${INSTALL_DIR}" \
    && curl -L "https://github.com/grailbio/bazel-compilation-database/archive/${VERSION}.tar.gz" | tar -xz \
    && ln -f -s "${INSTALL_DIR}/bazel-compilation-database-${VERSION}/generate.py" bazel-compdb
  )

  bazel-compdb # This will generate compile_commands.json in your workspace root.

  # To pass additional flags to bazel, pass the flags as arguments after --
  bazel-compdb -- [additional flags for bazel]

  # You can tweak some behavior with flags:
  # 1. To use the source dir instead of bazel-execroot for directory in which clang commands are run.
  bazel-compdb -s
  bazel-compdb -s -- [additional flags for bazel]
  # 2. To consider only targets given by a specific query pattern, say `//cc/...`. Also see below section for another way.
  bazel-compdb -q //cc/...
  bazel-compdb -q //cc/... -- [additional flags for bazel]
  ```

- [bazel-compile-commands-extractor](https://github.com/hedronvision/bazel-compile-commands-extractor#first-do-the-usual-workspace-setup)

  - Copy this to your `WORKSPACE`

  ```python
  load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")


  # Hedron's Compile Commands Extractor for Bazel
  # https://github.com/hedronvision/bazel-compile-commands-extractor
  http_archive(
      name = "hedron_compile_commands",

      # Replace the commit hash in both places (below) with the latest, rather than using the stale one here.
      # Even better, set up Renovate and let it do the work for you (see "Suggestion: Updates" in the README).
      url = "https://github.com/hedronvision/bazel-compile-commands-extractor/archive/ed994039a951b736091776d677f324b3903ef939.tar.gz",
      strip_prefix = "bazel-compile-commands-extractor-ed994039a951b736091776d677f324b3903ef939",
      # When you first run this tool, it'll recommend a sha256 hash to put here with a message like: "DEBUG: Rule 'hedron_compile_commands' indicated that a canonical reproducible form can be obtained by modifying arguments sha256 = ..."
      sha256 = "085bde6c5212c8c1603595341ffe7133108034808d8c819f8978b2b303afc9e7"
  )
  load("@hedron_compile_commands//:workspace_setup.bzl", "hedron_compile_commands_setup")
  hedron_compile_commands_setup()
  ```

  - run `bazel run @hedron_compile_commands//:refresh_all`
    Note: you have to `bazel run` this tool, not just `bazel build` it.

### Generate Compilation database with `bazel-stack-vscode-cc` vscode extension

Added this into `setting.json` and press `F1` to generate cpp code database

```json
...
  "bsv.cc.compdb.targets": [
    "<your target generate by cc_binary or cc_library rules>",
  ],
...
```
