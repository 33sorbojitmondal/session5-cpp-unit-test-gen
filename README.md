# Session 5: C++ Unit Test Generator with AI

## Overview
This project automates the generation and refinement of unit tests for C++ applications using Large Language Models (LLMs) like Ollama or GitHub-hosted models. The workflow is designed to iteratively generate, refine, and debug unit tests for the [orgChartApi](https://github.com/keploy/orgChartApi) C++ project, following strict YAML instructions for the LLM.

## Directory Structure
```
session5-cpp-unit-test-gen/
├── orgChartApi/           # Cloned C++ project (orgChartApi)
├── tests/                 # Generated and refined unit test files
├── yaml-prompts/          # YAML instruction files for LLM
│   ├── initial_test_gen.yaml
│   ├── refine_tests.yaml
│   └── fix_build.yaml
└── README.md              # This file
```

## Steps to Use the Generator
1. **Initial Test Generation**
   - For each C++ file (e.g., `main.cc`), send the code and `yaml-prompts/initial_test_gen.yaml` to your LLM.
   - Save the generated test as `tests/test_<filename>.cpp`.

2. **Refine the Tests**
   - Send the generated test(s) and `yaml-prompts/refine_tests.yaml` to the LLM.
   - The LLM will remove duplicates, add missing includes, and improve formatting.

3. **Build and Debug**
   - Attempt to build the project with the generated tests (using Google Test).
   - If the build fails, send the code, test, and build logs with `yaml-prompts/fix_build.yaml` to the LLM.
   - Repeat until the build passes.

4. **Test Coverage**
   - Run the tests and measure code coverage using GNU tools (`gcov`, `lcov`).
   - Optionally, send coverage data to the LLM for further improvements.

## How to Run Tests and Measure Coverage
- Use `g++` or `cmake` to build the project with Google Test and coverage flags.
- Run the tests in the `tests/` folder.
- Use `gcov` or `lcov` to generate a coverage report.

## What to Submit
- The `tests/` folder with all generated and refined test files
- The `yaml-prompts/` folder with all YAML instruction files
- A brief coverage report (text or screenshot)
- This `README.md` explaining your approach

## About the YAML Prompt Files
- `initial_test_gen.yaml`: Instructs the LLM to generate initial unit tests for a C++ file.
- `refine_tests.yaml`: Instructs the LLM to refine, deduplicate, and improve the tests.
- `fix_build.yaml`: Instructs the LLM to fix build errors using logs and code context.

---

**Reference C++ Project:** [orgChartApi](https://github.com/keploy/orgChartApi)

---

*Automate, iterate, and improve your C++ unit tests with the power of AI!* 