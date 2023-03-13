#include <cstdio>
#include <iostream>
#include <vector>
#include <fstream>
#include "../procedure_functions.cpp"
#include "../lexer.cpp"
using namespace std;

void test_Expression()
{   
    // Test case 1: valid expression
    ifstream input_file1("expression_test1.txt");
    vector<token_323> all_tokens1;
    int location1 = 0;
    bool test_result1 = false;
    int end_file1;

    while (!input_file1.eof()) {
        all_tokens1.push_back(lexer_323(input_file1));
        end_file1 = input_file1.peek();
        if (end_file1 == EOF) {
            break;
        }
    }

    test_result1 = procedure_Expression(all_tokens1, location1);
    
    cout << "Expression: Test result 1: ";
    test(test_result1);

    input_file1.close();

    // Test case 2: invalid expression
    ifstream input_file2("expression_test2.txt");
    vector<token_323> all_tokens2;
    int location2 = 0;
    bool test_result2 = false;
    int end_file2;

    while (!input_file2.eof()) {
        all_tokens2.push_back(lexer_323(input_file2));
        end_file2 = input_file2.peek();
        if (end_file2 == EOF) {
            break;
        }
    }

    test_result2 = procedure_Expression(all_tokens2, location2);
    
    cout << "Expression: Test result 2: ";
    test(test_result2);

    input_file2.close();

    /*
    expected output:
    Test case 1: should pass, as the input is a valid expression
    Test case 2: should fail, as the input is an invalid expression with a missing operator
    */
}
