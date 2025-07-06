#!/usr/bin/env python3
"""
Simple runner script for the AI-powered C++ Unit Test Generator
Usage: python run_test_generation.py [model_name]
"""

import sys
import subprocess
from pathlib import Path

def check_python_requirements():
    """Check if required Python packages are installed"""
    try:
        import yaml
        print("✓ PyYAML is available")
        return True
    except ImportError:
        print("✗ PyYAML not found. Installing...")
        try:
            subprocess.run([sys.executable, "-m", "pip", "install", "pyyaml"], check=True)
            print("✓ PyYAML installed successfully")
            return True
        except subprocess.CalledProcessError:
            print("✗ Failed to install PyYAML")
            return False

def check_ollama():
    """Check if Ollama is available"""
    try:
        result = subprocess.run(["ollama", "list"], capture_output=True, text=True)
        if result.returncode == 0:
            print("✓ Ollama is available")
            return True
        else:
            print("✗ Ollama is not running")
            return False
    except FileNotFoundError:
        print("✗ Ollama is not installed")
        return False

def main():
    print("🚀 AI-Powered C++ Unit Test Generator")
    print("=" * 50)
    
    # Check requirements
    if not check_python_requirements():
        return False
    
    if not check_ollama():
        print("\nPlease install Ollama first:")
        print("  Visit: https://ollama.ai/")
        print("  Then run: ollama pull llama3.1")
        return False
    
    # Determine model
    model = "llama3.1"
    if len(sys.argv) > 1:
        model = sys.argv[1]
    
    print(f"\nUsing model: {model}")
    
    # Import and run the generator
    try:
        from generate_tests import TestGenerator
        generator = TestGenerator(model)
        success = generator.run_full_workflow()
        
        if success:
            print("\n🎉 Test generation completed successfully!")
            print("📋 Check the following files:")
            print("  - tests/ directory for generated tests")
            print("  - LLM_STATS_REPORT.md for statistics")
            print("  - COVERAGE_REPORT.md for coverage details")
        else:
            print("\n❌ Test generation failed. Check the output above.")
        
        return success
        
    except Exception as e:
        print(f"Error running test generator: {e}")
        return False

if __name__ == "__main__":
    success = main()
    sys.exit(0 if success else 1) 