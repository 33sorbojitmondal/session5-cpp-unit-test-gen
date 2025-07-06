import sys
from pathlib import Path

# Usage: python generate_tests.py <cpp_file> <yaml_prompt>

def main():
    if len(sys.argv) != 3:
        print("Usage: python generate_tests.py <cpp_file> <yaml_prompt>")
        sys.exit(1)

    cpp_file = Path(sys.argv[1])
    yaml_file = Path(sys.argv[2])

    if not cpp_file.exists() or not yaml_file.exists():
        print("Error: File not found.")
        sys.exit(1)

    cpp_code = cpp_file.read_text()
    yaml_prompt = yaml_file.read_text()

    print("\n--- COPY BELOW TO YOUR LLM INTERFACE ---\n")
    print("# YAML INSTRUCTIONS:")
    print(yaml_prompt)
    print("\n# C++ CODE:")
    print(f"File: {cpp_file.name}\n")
    print(cpp_code)
    print("\n--- END ---\n")
    print("Paste the above into your LLM (Ollama, etc.) and save the output as tests/test_" + cpp_file.stem + ".cpp")

if __name__ == "__main__":
    main() 