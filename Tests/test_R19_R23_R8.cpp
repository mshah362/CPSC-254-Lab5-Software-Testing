#include <cstdio>
#include <iostream>
#include <vector>
#include <fstream>
#include "../procedure_functions.cpp"
#include "../lexer.cpp"

using namespace std;

void test_Return();
void test_Condition();
void test_Declaration();
void test();

int main(int argc, char *argv[])
{
	test_Return();
	test_Condition();
	test_Declaration();

    return 0;
}

void test(bool res)
{
	if (res)
	{
		cout << " worked!" << endl;
	}
	else
	{
		cout << " failed!" << endl;
	}
}

void test_Return()
{
	ifstream input_file("R19_test.txt");
    vector<token_323> all_tokens;

    int location = 0;
    
    bool test_results = false;
    int end_file;

    while (!input_file.eof()) {
        all_tokens.push_back(lexer_323(input_file));
        end_file = input_file.peek();
        if (end_file == EOF) {
            break;
        }
    }

    test_results = procedure_Return(all_tokens , location);
    cout << "Return: Test result 1";
    test(test_results);

    input_file.close();

/*
Expected output:

   Divding by zero is an invalid operation, it raises a "zerodivisionError" which then causes
the program to crash 
*/

}

void test_Condition(){

	ifstream input_file("R23_test.txt");
    vector<token_323> all_tokens;

    int location = 0;
    
    bool test_results = false;
    int end_file;

    while (!input_file.eof()) {
        all_tokens.push_back(lexer_323(input_file));
        end_file = input_file.peek();
        if (end_file == EOF) {
            break;
        }
    }

    test_results = procedure_Condition(all_tokens , location);
    cout << "Condition: Test result 1";
    test(test_results);

    input_file.close();

/*
Expected output:

       This is because even though it should be true, The value of x and y may not be exactly equal
       to 0.1 and 0.2 due to floating-point arithmetic which can cause a slight rounding error.
       So the adding resulted in a slightly different answer from 0.3 causing the condition to be false
*/

}

void test_Declaration(){

	ifstream input_file("R12_test.txt");
    vector<token_323> all_tokens;

    int location = 0;
    
    bool test_results = false;
    int end_file;

    while (!input_file.eof()) {
        all_tokens.push_back(lexer_323(input_file));
        end_file = input_file.peek();
        if (end_file == EOF) {
            break;
        }
    }

    test_results = procedure_Return(all_tokens , location);
    cout << "Declaration: Test result 1";
    test(test_results);

    input_file.close();

/*
Expected output:

        The value 5.5 is converted to an integer before it is assined to the variable x.
        This makes the declaration appear true even though it should be false due to a type
        mismatch.
*/
}