# Contribution Guide

## Basic environment setup

### Conda installation

conda installation is recommended for managing python environment.
[Conda installation guide](https://conda.io/projects/conda/en/latest/user-guide/install/index.html)

### Create environment

```bash
conda create -n rperf python=3.8 -y -c conda-forge
```

### Install dependencies through requirements_dev.txt

```bash
conda install --file requirement_dev.txt -c conda-forge -y
conda install prettier=3.2.5 -c conda-forge -y
```

or accelerate the installation through tsinghua mirror

```bash
conda install --file requirement_dev.txt -c https://mirrors.tuna.tsinghua.edu.cn/anaconda/pkgs/pro -c https://mirrors.tuna.tsinghua.edu.cn/anaconda/pkgs/main -y
```

### pre-commit git hook installation

1. install git hook through `pre-commit install`.
1. before `git commit` make sure to run `pre-commit run`

## Testing

### Run all tests

```bash

pytest -s tests
========================= test session starts =========================
platform linux -- Python 3.8.18, pytest-8.1.1, pluggy-1.4.0
rootdir: /root/Desktop/dockerVolumn/profiler
collected 2 items

tests/test_dta.py ..

========================== 2 passed in 0.85s ==========================
```

## VScode setting up

1. install extensions

   - Python
   - Pylance
   - Pylint
   - Python Debugger
   - yapf
   - GitLab Workflow: `Add Account` -> input url -> input token

2. the recommended settings are in `vscode/settings.json`

## How to Contribute

1. **Fork the Repository**: Start by forking the repository to your GitLab account.

2. **Create a Branch**: Create a new branch for your feature or bug fix. Use a descriptive name that reflects the changes you plan to make.

   ```bash
   git checkout -b my-feature-branch
   ```

3. **Make Changes**: Implement your changes, following the project's coding conventions and guidelines.

4. **Run the precommit in your localhost**: Run the precommit in your localhost to ensure the code style and quality.

   ```bash
   pre-commit run
   ```

5. **Test Your Changes**: Ensure that your changes don't break existing functionality by running the project's tests.

6. **Commit Your Changes**: Commit your changes with a descriptive commit message that explains the changes you've made.

   ```bash
   git commit -m "Add new feature: Description of the feature"
   ```

7. **Push to Your Fork**: Push your changes to your forked repository.

   ```bash
   git push origin my-feature-branch
   ```

8. **Submit a Pull Request**: Go to the original repository and create a new pull request, describing the changes you've made and their purpose.

   **NB: please choose the `squash` option when merging the pull request.**

## Code Style and Guidelines

### Naming Conventions

This project adheres to the [Google Python Style Guide](https://google.github.io/styleguide/pyguide.html) for coding conventions and best practices. To ensure code quality and consistency, we use Pylint as our linter tool, with a customized configuration tailored for our project.

- Variables: Use lowercase with words separated by underscores (e.g., my_variable).
- Constants: Use uppercase with words separated by underscores (e.g., CONSTANT_NAME).
- Functions: Use lowercase with words separated by underscores (e.g., my_function).
- Classes: Use CapitalizedWords with no separators (e.g., MyClass).
- Methods: Use lowercase with words separated by underscores (e.g., my_method).
- Modules: Use lowercase with words separated by underscores (e.g., my_module.py).

### Code Formatting

This project follows the PEP 8 style guide for Python code. Please ensure that your code follows the style guide to maintain consistency across the project.

- Column Limit: Code lines should be wrapped at 80 characters to ensure readability across different environments and tools.
- Indent Width: Indentation should use 2 spaces, as recommended by PEP 8.
- Split Before Named Assigns: For better readability, named assignments should be split onto separate lines.
- Spaces Around Power Operator: Spaces should be added around the power operator (\*\*) for better readability.
- Dedent Closing Brackets: Closing brackets should be dedented to the same level as the opening line.
- Coalesce Brackets: Brackets should be coalesced when possible, improving code readability.

## Reporting Bugs

If you encounter any bugs or issues, please report them by opening a new issue in the repository. Provide a clear description of the problem, steps to reproduce it, and any relevant information that could help diagnose and fix the issue.

## Suggesting Enhancements

If you have ideas for new features or enhancements, feel free to open a new issue in the repository and describe your suggestion. We appreciate any feedback that can improve the project.

## Code of Conduct

Please note that this project adheres to the Code of Conduct. By participating in this project, you are expected to uphold this code.
