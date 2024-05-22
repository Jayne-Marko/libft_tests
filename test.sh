#!/bin/bash

# Compile the library
# make re 

test_files=$(find . -name 'test_*.c')

# Loop through each test file
for test_file in $test_files; do
    # Extract the test name from the file path
    test_name=$(basename "$test_file" .c)
    
    # Compile the test file and link with the library
    gcc -o ./tests/"$test_name" "$test_file" -L./ -lft -I ./

    # Run the test and capture output
    output=$(./tests/"$test_name")

    # Print results
    echo "Test function ${test_name#test_}:"
    echo "$output"
    errors=$(echo "$output" | grep -c "Expected")
    if [ $errors -eq 0 ]; then
    echo -e "\033[32m \033[1mErrors: $errors, Passed.\033[0m"
	else
    echo -e "\033[31m \033[1mErrors: $errors, not pass.\033[0m"
	fi
    echo ""
done