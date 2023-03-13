#include <cstdio>
#include <iostream>
#include <vector>
#include <fstream>
#include "../procedure_functions.cpp"
#include "../lexer.cpp"
using namespace std;

void test_procedure_Term() {
    ifstream input_file1("r26_test1.txt");
    vector<token_323> all_tokens1;

    int location1 = 0;
    bool test_results1 = false;
    int end_file1;

    while (!input_file1.eof()) {
        all_tokens1.push_back(lexer_323(input_file1));
        end_file1 = input_file1.peek();
        if (end_file1 == EOF) {
            break;
        }
    }

    test_results1 = procedure_Term(all_tokens1, location1);

    cout << "Term: Test result 1: ";
    test(test_results1);

    input_file1.close();


    ifstream input_file2("r26_test2.txt");
    vector<token_323> all_tokens2;

    int location2 = 0;
    bool test_results2 = false;
    int end_file2;

    while (!input_file2.eof()) {
        all_tokens2.push_back(lexer_323(input_file2));
        end_file2 = input_file2.peek();
        if (end_file2 == EOF) {
            break;
        }
    }

    test_results2 = procedure_Term(all_tokens2, location2);

    cout << "Term: Test result 2: ";
    test(test_results2);

    input_file2.close();

    /*
    Expected output:
    The first test should pass because it follows the correct rule structure for term,
    The second test should fail because it violates the structure and does not follow the rules
    */
}
