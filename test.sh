#!/bin/bash

# Colors for output
GREEN='\033[38;5;84m'
RED='\033[38;5;197m'
CHECKMARK='\xE2\x9C\x93'
GREY='\033[38;5;8m'
DEFAULT='\033[0m'
BOLD='\033[1m'

# Compile the library
make re 

# Function to compile and run a test file
run_test() {
    local test_file="$1"
    local test_name=$(basename "$test_file" .c)

	# Compile the test file and link with the library
    gcc -o ./tests/"$test_name" "$test_file" -L./ -lft -I ./

    # Run the test and capture output
    output=$(./tests/"$test_name")

    # Print results
    echo "Test function ${test_name#test_}:"

	echo "$output" | grep "Expected"
    errors=$(echo "$output" | grep -c "Expected")
	tests=$(echo "$output" | grep -c "as expected")
    if [ $errors -eq 0 ]; then
        echo -e "${GREEN}${CHECKMARK}Tests: $tests, Errors: $errors, Passed.${DEFAULT}"
    else
        echo -e "${RED}Tests: $tests, Errors: $errors, not pass.${DEFAULT}"
    fi
    echo ""
}

run_test_function() {
    local test_file="$1"
    local test_name=$(basename "$test_file" .c)

	# Compile the test file and link with the library
    gcc -o ./tests/"$test_name" "$test_file" -L./ -lft -I ./

    # Run the test and capture output
    output=$(./tests/"$test_name")

    # Print results
    echo "Test function ${test_name#test_}:"

	echo "$output"
    errors=$(echo "$output" | grep -c "Expected")
	tests=$(echo "$output" | grep -c "as expected")
    if [ $errors -eq 0 ]; then
        echo -e "${GREEN}${CHECKMARK}Tests: $tests, Errors: $errors, Passed.${DEFAULT}"
    else
        echo -e "${RED}Tests: $tests, Errors: $errors, not pass.${DEFAULT}"
    fi
    echo ""
}

# Check if a specific test name is provided
if [ $# -eq 1 ]; then
    test_file="./tests/test_$1.c"
    if [ -f "$test_file" ]; then
        run_test_function "$test_file"
    else
        echo "Test file $test_file not found."
        exit 1
    fi
else
    # Find all test files
    test_files=$(find ./tests -name 'test_*.c')

    # Loop through each test file
    for test_file in $test_files; do
        run_test "$test_file"
    done
fi
