/*
 * countsubstr.cpp
 *
 *  Created on: Mar 26, 2019
 *      Author: srinivasanmurali
 */
#include <iostream>
#include <stack>
using namespace std;

int main() {
	//code
	int num_tc = 0;
	stack<char> stk;
	cin>>num_tc;
	if (num_tc < 1 || num_tc > 100) {
	    cout<<"Invalid tc num, valid 1 - 100"<<endl;
	    return 1;
	}
	int num_sub;
	for (int i = 0; i < num_tc; i++) {
	    num_sub = 0;
	    string st = "";
	    cin>>st;
	    for(int j = 0; j < (int)st.size(); j++) {
	        if (st.at(j) == '1') {
	            if (stk.size() == 0) {
	                stk.push(st.at(j));
	            } else {
	                num_sub++;
	                while(stk.size()) {
	                    stk.pop();
	                }
	                stk.push(st.at(j));
	                if (stk.size() == 1 && num_sub > 1) {
	                    num_sub++;
	                }
	            }
	        } else {
	            if (stk.size() > 0) {
	                stk.push(st.at(j));
	            }
	        }
	    }
	    cout<<num_sub<<endl;
	}
	return 0;
}



