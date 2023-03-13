#include <cstdio>
#include <iostream>
#include <vector>
#include <fstream>
#include "../procedure_functions.cpp"
#include "../lexer.cpp"

using namespace std;

void test_Qualifier();
void test_Body();
void test_OptDeclaration();
void test();

int main(int argc, char *argv[])
{
	test_Qualifier();
	test_Body();
	test_OptDeclaration();

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

void test_Qualifier()
{
	ifstream input_file("r8_r9_test1.txt");
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

	test_results = procedure_Qualifier(all_tokens, location);
	
	cout << "Qualifier: Test result 1";
	test(test_results);

    input_file.close();

	ifstream input_file2("r8_r9_test2.txt");
    vector<token_323> all_tokens2;
    test_results = false;
    end_file = 0;

    while (!input_file2.eof()) {
        all_tokens2.push_back(lexer_323(input_file2));
        end_file = input_file2.peek();
        if (end_file == EOF) {
            break;
        }
    }

	test_results = procedure_Qualifier(all_tokens2, location);
	
	cout << "Qualifier: Test result 2";
	test(test_results);

    input_file2.close();

    /*
    expected output:
    	procedure_Qualifier function should return True for the first input, then False for the second input as it is not a
    	Qualifier according to the function though it should be
    */


}

void test_Body()
{   
	ifstream input_file("r8_r9_test1.txt");
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

	test_results = procedure_Qualifier(all_tokens, location);
	
	cout << "Body: Test result 1";
	test(test_results);

    input_file.close();

	ifstream input_file2("r8_r9_test2.txt");
    vector<token_323> all_tokens2;
    test_results = false;
    end_file = 0;

    while (!input_file2.eof()) {
        all_tokens2.push_back(lexer_323(input_file2));
        end_file = input_file2.peek();
        if (end_file == EOF) {
            break;
        }
    }

	test_results = procedure_Qualifier(all_tokens2, location);
	
	cout << "Body: Test result 2";
	test(test_results);

    input_file2.close();
	
	/*
    expected output:
    	First should work because there is an ending bracket for each opening bracket : {{} }
		Second should fail because there is no end bracket for the second braopening bracket : {{}
    */
}

void test_OptDeclaration()
{   
	ifstream input_file("r10_test1.txt");
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

	test_results = procedure_Opt_Declaration_List(all_tokens, location);
	
	cout << "Opt_Dec_List: Test result 1";
	test(test_results);

    input_file.close();

	ifstream input_file2("r10_test2.txt");
    vector<token_323> all_tokens2;
    test_results = false;
    end_file = 0;

    while (!input_file2.eof()) {
        all_tokens2.push_back(lexer_323(input_file2));
        end_file = input_file2.peek();
        if (end_file == EOF) {
            break;
        }
    }

	test_results = procedure_Opt_Declaration_List(all_tokens2, location);
	
	cout << "Opt_Dec_List: Test result 2";
	test(test_results);

    input_file2.close();

   	/*
	expected output:
   	There should be no error with both of these tests since this procedure simply tests for whether the optional declaration list, 
   	meaning the declaration of non-parameters, are there or not, and returns true regardless because you don't need to have a declaration list. 
	It will however, trigger errors from the normal declaration procedure since its recursively defined

	Not sure why this test returned "error, expecting <IDs>"" even though they were included in the second 
    */
}