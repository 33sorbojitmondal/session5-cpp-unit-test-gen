# Session 5: AI-Powered C++ Unit Test Generator

## Overview
This project automates the generation and refinement of unit tests for C++ applications using Large Language Models (LLMs) via Ollama. The workflow automatically generates, refines, builds, and tests unit tests for the [orgChartApi](https://github.com/keploy/orgChartApi) C++ project.

## Features
- 🤖 **AI-Powered Test Generation**: Uses Ollama to generate comprehensive unit tests
- 🔄 **Automated Refinement**: Removes duplicates and improves test quality
- 🔧 **Build Error Fixing**: Automatically fixes compilation errors
- 📊 **Coverage Reporting**: Generates test coverage statistics
- 📋 **LLM Statistics**: Provides detailed statistics for reviewers

## Prerequisites
1. **Ollama**: Install Ollama and pull a model (e.g., `llama3.1`)
2. **Python 3.7+**: For running the test generation scripts
3. **CMake**: For building the C++ tests
4. **Google Test**: For the testing framework
5. **Drogon**: For the web framework (if testing controllers)

## Quick Start

### 1. Install Requirements
```bash
# Install Python dependencies
pip install -r requirements.txt

# Install Ollama (if not already installed)
# Visit: https://ollama.ai/
# Then pull a model:
ollama pull llama3.1
```

### 2. Run the Automated Test Generation
```bash
# Run with default model (llama3.1)
python run_test_generation.py

# Or specify a different model
python run_test_generation.py codellama
```

### 3. Check Results
After completion, check:
- `tests/` directory for generated test files
- `LLM_STATS_REPORT.md` for LLM usage statistics
- `COVERAGE_REPORT.md` for coverage details

## Directory Structure
```
session5-cpp-unit-test-gen/
├── orgChartApi/           # Cloned C++ project (orgChartApi)
├── tests/                 # Generated and refined unit test files
│   ├── test_*.cpp         # Generated test files
│   └── CMakeLists.txt     # Build configuration
├── yaml-prompts/          # YAML instruction files for LLM
│   ├── initial_test_gen.yaml
│   ├── refine_tests.yaml
│   └── fix_build.yaml
├── generate_tests.py      # Main test generation engine
├── run_test_generation.py # Simple runner script
├── requirements.txt       # Python dependencies
├── LLM_STATS_REPORT.md   # Generated statistics (for reviewers)
└── README.md             # This file
```

## How the AI Workflow Works

### Phase 1: Initial Test Generation
- Analyzes each C++ file in the orgChartApi project
- Sends code and YAML instructions to Ollama
- Generates comprehensive unit tests using Google Test
- Saves tests as `test_<filename>.cpp`

### Phase 2: Test Refinement
- Reviews all generated tests
- Removes duplicates and redundant tests
- Adds missing includes and dependencies
- Improves code formatting and structure

### Phase 3: Build and Debug
- Attempts to build tests with CMake
- If build fails, sends error logs to Ollama
- Automatically fixes compilation errors
- Repeats until successful build

### Phase 4: Coverage and Statistics
- Runs the generated tests
- Measures code coverage (when possible)
- Generates comprehensive statistics report

## Manual Usage (Advanced)

If you prefer manual control:

```bash
# Generate tests for a specific file
python generate_tests.py orgChartApi/main.cc yaml-prompts/initial_test_gen.yaml

# Build tests manually
cd tests
cmake . -B build
cmake --build build

# Run tests
./build/runTests
```

## YAML Prompt Files

### `initial_test_gen.yaml`
Instructs the LLM to generate initial unit tests with proper includes and Google Test structure.

### `refine_tests.yaml`
Instructs the LLM to refine tests by removing duplicates and improving quality.

### `fix_build.yaml`
Instructs the LLM to fix compilation errors based on build logs.

## LLM Statistics for Reviewers

The system generates `LLM_STATS_REPORT.md` with:
- Total Ollama API calls made
- Model used and response times
- Files processed and tests generated
- Build fixes applied
- Coverage statistics

This provides complete transparency about LLM usage for the Keploy Fellowship review process.

## Troubleshooting

### Common Issues
1. **Ollama not found**: Make sure Ollama is installed and running
2. **Model not available**: Run `ollama pull llama3.1` to download the model
3. **Build failures**: Check that CMake, Google Test, and Drogon are installed
4. **Permission errors**: Ensure the script has write permissions

### Debug Mode
For verbose output, check the console logs during execution.

## What to Submit for Keploy Fellowship

1. **Generated Tests**: The `tests/` directory with all generated test files
2. **Statistics Report**: `LLM_STATS_REPORT.md` showing LLM usage
3. **Coverage Report**: `COVERAGE_REPORT.md` with test coverage results
4. **This README**: Explaining your approach and workflow

## Architecture

```
[C++ Source Files] → [Ollama LLM] → [Generated Tests] → [Refinement] → [Build] → [Coverage]
       ↓                ↓              ↓                ↓            ↓         ↓
   [Analysis]      [AI Generation]  [Deduplication]  [Error Fix]  [Test Run] [Report]
```

The workflow is fully automated and provides comprehensive statistics for review.

---

**Reference C++ Project:** [orgChartApi](https://github.com/keploy/orgChartApi)

*Automate, iterate, and improve your C++ unit tests with the power of AI!* 