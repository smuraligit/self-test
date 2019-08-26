/*Algorithm

Input: Get num of test cases (N)
Two numbers

Output:
Product of two numbers for i = 1 to N

- Get the number of test cases (N)
- Allocate a two dimensional integer array of size N
- For each N, get the user input as string
    - Tokenize the string and convert tokens into two integers
    - Store those two integers in the right position of 2D array
- Iterate 2D array and for each row, compute the product of the
  Values stored in the column and output it. */


/*
 * To do,
 * - Find out why cin stops on encountering space on user input stream?
 */


#include <iostream>
#include <sstream>
#include <string>

using namespace std;

#define NUM_COL 2

int main() {
    int num_test_case = 0;
    string test_case_str;
    string prod_inp_str;
    string token_str;
    int token;
    int i, j;
    int prod_res;

    getline(cin, test_case_str);
    stringstream ss0(test_case_str);
    ss0>>num_test_case;
    if (num_test_case < 1 && num_test_case > 100) {
        cout<<"Number of test case must be >= 1 and <= 100"<<endl;
        return 1;
    }
    int user_inp[num_test_case][NUM_COL];
    for(i = 0; i < num_test_case; i++) {
        for(j = 0; j < NUM_COL; j++) {
            user_inp[i][j] = 0;
        }
    }

    for(i = 0, j = 0; i < num_test_case; i++) {
    	getline(cin, prod_inp_str);
    	stringstream ss(prod_inp_str);
    	while(ss>>token_str) {
    		stringstream ss1(token_str);
    		if (j == 2) {
    			cout<<"Entered more than 2 numbers as input, please enter 2 numbers per test case"<<endl;
    			return 1;
    		}
    		ss1>>token;
    		if (token < 0 || token > 100) {
    			cout<<"Input number must be >= 0 and <= 100"<<endl;
    			return 1;
    		}
    		user_inp[i][j++] = token;
    	}
    	j = 0;
    }

    for(i = 0; i < num_test_case; i++) {
        prod_res = 1;
        for(j = 0; j < NUM_COL; j++) {
            prod_res *= user_inp[i][j];
        }
        cout<<prod_res<<endl;
    }
    return 0;
}
