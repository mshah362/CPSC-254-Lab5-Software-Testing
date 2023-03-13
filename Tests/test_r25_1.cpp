#include <cstdio>
#include <iostream>
#include <vector>
#include <fstream>
#include "../procedure_functions.cpp"
#include "../lexer.cpp"
using namespace std;

void test_procedure_Expression_q() {
    ifstream input_file("expression_q_test1.txt");
    vector<token_323> all_tokens;
    int location = 0;
    bool test_results = false;

    while (!input_file.eof()) {
        all_tokens.push_back(lexer_323(input_file));
    }

    test_results = procedure_Expression_q(all_tokens, location);
    cout << "Expression_q: Test result 1";
    test(test_results);
    input_file.close();


    ifstream input_file2("expression_q_test2.txt");
    vector<token_323> all_tokens2;
    location = 0;
    test_results = false;

    while (!input_file2.eof()) {
        all_tokens2.push_back(lexer_323(input_file2));
    }

    test_results = procedure_Expression_q(all_tokens2, location);
    cout << "Expression_q: Test result 2";
    test(test_results);
    input_file2.close();

    /*
    expected output:
        Test 1 should work as it is just one single '+' token followed by a valid Term and valid Expression'
        Test 2 should fail because there is an extra '+' token with no Term or Expression' following it
    */
}
