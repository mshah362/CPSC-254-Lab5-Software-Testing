#include <cstdio>
#include <iostream>
#include <vector>
#include <fstream>
#include "../procedure_functions.cpp"
#include "../lexer.cpp"
using namespace std;
void test_Primary();
int main(int argc, char *argv[])
{
  test_Primary();
  return 0;
}
void test_Primary()
{
    std::ifstream input_file("input.txt");
    bool test_results = false;
    std::vector<token_323> all_tokens;
    int loc = 0;
    int check_eof;

    while (!input_file.eof()) {
        all_tokens.push_back(lexer_323(input_file));
        check_eof = input_file.peek();
        if (check_eof == EOF) {
            break;
        }
    }

    test_results = procedure_Factor(all_tokens, loc);

    if (test_results == false) {
        std::cout << "Failed: Testing of R28<Primary>" << std::endl;
    } else {
        std::cout << "Passed: Testing of R28<Primary>" << std::endl;
    }

    std::cout << "\nHere are all the tokens in the vector:" << std::endl;
    for (auto token : all_tokens) {
        token.token_print_helper();
    }

    input_file.close();

    return;
}