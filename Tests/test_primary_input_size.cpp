// Test the vecotr<token_323> size limit.
// Test case #1 from test_cases.txt
// 192153584101141163

#include <cstdio>
#include <iostream>
#include <vector>
#include <fstream>
#include "../procedure_functions.cpp"
#include "../lexer.cpp"
using namespace std;

void test_primary_input_size(long size) {
    vector<token_323> tokens;
    long max_size = tokens.max_size();
    long input_size = size;
    std::string result = "Failed";
    std::cout << "Maximum amount of elements for a vecotr<token_323> is " << max_size << std::endl;

    if (input_size > max_size) {
        std:: cout << "Input size test: " << result << ".\n" << std::endl;
        std::cout << "Test failed because vector<token_323 must contain at most " << max_size << " elements.\n";
    } else {
        result = "Passed";
        std:: cout<< "Input size test: " << result << std::endl;
    }
}

int main() {
    long test_vect_size = 192153584101141163;
    test_primary_input_size(test_vect_size);

    return 0;
}

