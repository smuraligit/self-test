#include <iostream>
using namespace std;

int main() {
int first;
char second;
float third;
cin>>first>>second>>third;
cout<<first<<endl<<second<<endl<<third<<endl;
return 0;
}

/*
 #include <iostream>
#include <sstream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
	string userInp = "";
	string tok = "";

	int a = 0;
	char b;
	float c = 0.0;
	double d = 0.0;

	//Read line
    getline(cin, userInp);
    if ("" == userInp) {
    	cout<<"Invalid user input"<<endl;
    	return 1;
    }

    //tokenize
    stringstream ss(userInp);
    while (getline(ss, tok, ' ')) {
    	stringstream ss1(tok);
    	ss1 >> a;
    	if (!ss1.eof() || ss1.fail()) {
    		//Try float
    		stringstream ss2(tok);
    		ss2 >> c;
    		if (!ss2.eof() || ss2.fail()) {
    			//Try double
    			stringstream ss3(tok);
    			ss3 >> d;
    			if (!ss3.eof() || ss3.fail()) {
    				//Try char
    				stringstream ss4(tok);
    				ss4 >> b;
    				if (ss4.fail()) {
    					cout<<"Not any of valid basic types "<<tok<<endl;
    					return 1;
    				} else {
    					cout<<b<<endl;
    				}
    			} else {
    				cout<<d<<endl;
    			}
    		} else {
    			//test if float or double by comparing token after decimal point .
    			string tmp_string = tok;
    			stringstream ss_tmp(tmp_string);
    			string tok_check;
    			while (getline (ss_tmp, tok_check, '.')) {

    			}
    			if (tok_check.length() > 7) {
    				stringstream ss4(tok);
    				ss4 >> d;
    				if (!ss4.eof() || ss4.fail()) {
    					cout<<"Not any of valid basic types "<<tok<<endl;
    					return 1;
    				} else {
    					cout<<std::setprecision(18)<<d<<endl;
    				}
    			} else {
    				cout<<c<<endl;
    			}
    		}
    	} else {
    	    cout<<a<<endl;
        }
    }
    return 0;
}

 */
