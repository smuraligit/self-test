/*
 * finduncommon.cpp
 *
 *  Created on: Apr 1, 2019
 *      Author: srinivasanmurali
 */

#include <iostream>
#include <map>
#include <iterator>
#include <algorithm>
#include <cstring>
using namespace std;

void printUncommon(string s1, string s2) {
    map<char, int> m;
    int i;

    for(i = 0; i < (int)s1.length(); i++){
        if (m.find(s1.at(i)) == m.end()) {
            //m.insert({s1.at(i), 1});
        	m[s1.at(i)] = 1;
        }
    }
    string out = "";
    for(i = 0; i < (int)s2.length(); i++) {
        if (m.find(s2.at(i)) == m.end()) {
        	if (!strchr(out.c_str(), s2.at(i))) {
        		out.append(1, s2.at(i));
        	}
        } else {
        	if (m[s2.at(i)] > 0) {
        		m[s2.at(i)] -= 1;
        	}
        }
    }
    map<char, int>::iterator it;
    for(it = m.begin(); it != m.end(); ++it) {
        if(it->second > 0) {
            out.append(1, it->first);
        }
    }
    sort(out.begin(), out.end());
    cout<<out<<endl;
    return;
}

int main() {
	//code
	int num_tc = 0;
	cin>>num_tc;
	if (num_tc < 1 || num_tc > 100) {
	    cout<<"Invalid, valid 1 - 100"<<endl;
	    return 1;
	}
	string s1, s2;
	for(int i = 0; i < num_tc; i++) {
	    s1 = "";
	    s2 = "";
	    cin>>s1;
	    if (s1.empty()) {
	        cout<<"Null"<<endl;
	        return 1;
	    }
	    cin>>s2;
	    if (s2.empty()) {
	        cout<<"Null s2"<<endl;
	        return 1;
	    }
	    if (s1 == s2) {
	        cout<<s1<<endl;
	        continue;
	    }
	    printUncommon(s1, s2);
	}
	return 0;
}


