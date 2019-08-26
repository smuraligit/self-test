/*
 * stringgame.cpp
 *
 *  Created on: Mar 29, 2019
 *      Author: srinivasanmurali
 */

#include <iostream>
#include <map>
#include <iterator>
using namespace std;

long int getPow(int n, int a) {
    long int res = 1;
    for (int i = 0; i < a; i++) {
        res *= n;
    }
    return res;
}

void findMaxAndUpdate(map<char, int> & m, int k) {
    int count;
    char maxChar;
    map<char, int>::iterator it;
    while (k--) {
    	count = 0;
        for(it = m.begin(); it != m.end(); ++it) {
            if (it->second > count) {
                count = it->second;
                maxChar = it->first;
            }
        }
        if (m[maxChar] > 0) {
        	m[maxChar] = m.at(maxChar) - 1;
        }
    }
}

long int printMinVal(string st, int k) {
    long int ans = 0;
    map<char, int> m;
    map<char, int>::iterator it;
    int i;
    for (i = 0; i < (int)st.size(); i++) {
        //m.insert(st.at(i), 0);
        m[st.at(i)] = 0;
    }
    for (i = 0; i < (int)st.size(); i++) {
        //m.insert(st.at(i), m[st.at(i)]+1);
        m[st.at(i)] += 1;
    }
    findMaxAndUpdate(m, k);

    for (it = m.begin(); it != m.end(); ++it) {
    	//ans += getPow(it->second, it->second);
    	ans += (it->second * it->second);
    }
    return ans;
}

int main() {
	//code
	int num_tc = 0;
	cin>>num_tc;
	if (num_tc < 1 || num_tc > 100) {
	    cout<<"Invalid tc num, valid 1 - 100"<<endl;
	    return 1;
	}
	string st="";
	int k = 0;
	for (int i = 0; i < num_tc; i++) {
	    cin>>st;
	    cin>>k;
	    cout<<printMinVal(st, k);
	    cout<<endl;
	}
	return 0;
}

