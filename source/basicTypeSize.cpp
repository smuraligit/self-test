/*Algorithm:

To do:
Given N test cases, display size of type

example
input
4
23
b
3.14
7.7289287398

4
1
4
8

- Get the number of test cases input from user
- Until the number of test cases, read the input and store it in an array (what type - probably string or vector)
- Iterate the array and convert to each of the four types and check if it matches to any one of the type,
- if it matches, then display the size of the type

Another approach

- Rather than storing the inputs in the array, we can process each input and store the output in the array
- Finally once all the inputs are processed, display the output array elements (Advantage - we know we are displaying numbers, so we can have an integer array, whereas inputs could be of any type, need to deal with
conversions)

TODO - find out elegant solution may be boost lexical cast

*/

#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <boost/lexical_cast.hpp>
using namespace std;
//using boost::lexical_cast;
using boost::bad_lexical_cast;

int main() {
	string num_tc_str = "";
	string inp_str = "";
    int a;
    char b;
    float c;
    double d;
    int num_tc = 0;
    int i;
    vector<int> out_size;

    getline(cin, num_tc_str);

    stringstream ss(num_tc_str);
    ss>>num_tc;
    if (ss.fail()) {
    	cout<<"Error: Testcase number is not a number"<<endl;
    	return 1;
    }

    if (num_tc < 1 || num_tc > 100) {
        cout<<"Error: Testcase number should be between 1 and 100"<<endl;
        return 1;
    }

    for(i = 0; i < num_tc; i++) {
    	getline(cin, inp_str);
    	stringstream ss1(inp_str);
    	ss1>>a;

    	if (!ss1.eof() || ss1.fail()) {
    		//cout<<"inp str "<<inp_str<<endl;
    		stringstream ss2(inp_str);
    		//ss2 << fixed << setprecision(15);
    		ss2 >> c;
    		if (!ss2.eof() || ss2.fail()) {
    			stringstream ss3(inp_str);
    			ss3>>d;
    			if (!ss3.eof() || ss3.fail()) {
    				stringstream ss4(inp_str);
    				ss4>>b;
    				if (ss4.fail()) {
    					cout<<"Number entered is not any of the basic types " <<endl;
    					return 1;
    				} else {
    					//cout<<"Its a char"<<endl;
    					out_size.push_back(sizeof(char));
    					ss4.clear();
    				}
    			} else {
    				//cout<<"Its a double"<<endl;
    				out_size.push_back(sizeof(double));
    				ss3.clear();
    			}
    		} else {
    			//check size of string (could be double as well)
    			string inp_str_tmp = inp_str;
    			string inp_str_tok = "";
    			stringstream ss_tmp(inp_str_tmp);
    			while(getline(ss_tmp, inp_str_tok, '.')) {

    			}

                //cout<<"inp_str_tok "<<inp_str_tok<<endl;

    			if (inp_str_tok.length() > 7) {
    			    stringstream ss5(inp_str);
    			    ss5>>d;
    			    if (!ss5.eof() || ss5.fail()) {
    			    	cout<<"Not a double"<<endl;
    			    } else {
    			    	//cout<<"Its a double"<<endl;
    			    	out_size.push_back(sizeof(double));
    			    	ss5.clear();
    			    }
    			} else {
    				//cout<<"Its a float "<<c<<endl;
    				out_size.push_back(sizeof(float));
    				ss2.clear();
    			}
    		}
    	} else {
    		//cout<<"Its an integer"<<endl;
    		out_size.push_back(sizeof(int));
    		ss1.clear();
    	}
    }



    string str = "5";
    string str1 = "6.5";
    string str2 = "7.82794781984778";
    string str3 = "8.9817498174981274";
    int i_val;
    float f_val, f_val1;
    double d_val;

    std::setprecision(17);
    i_val = boost::lexical_cast<int>(str);
    f_val = boost::lexical_cast<float>(str1);
    //f_val1 = boost::lexical_cast<float>(str2);
    //d_val = boost::lexical_cast<double>(str3);

    try{
    	f_val1 = boost::lexical_cast<float>(str2);
    	d_val = boost::lexical_cast<double>(str3);

    } catch (bad_lexical_cast &e) {
    	cout<<"Exception caught: "<<e.what()<<endl;

    }

    cout<<"int val "<<i_val<<endl;
    cout<<"float val "<<f_val<<endl;
    cout<<"float val1 "<<f_val1<<endl;
    cout<<"double val "<< std::setprecision(17) << d_val<<endl;

    //display output sizes
    for(i = 0; i < (int) out_size.size(); i++) {
        cout<<out_size.at(i)<<endl;
    }



    return 0;
}
