/*
 * countpalin.cpp
 *
 *  Created on: Apr 19, 2019
 *      Author: srinivasanmurali
 */


#include <iostream>
using namespace std;

bool checkPal(string s, int start, int end) {
	int i = start;
	int j = end;
	bool res = true;
	while(i < j) {
		if (s[i]==s[j]) {
			i++;
			j--;
		} else {
			res = false;
			break;
		}
	}
	return res;
}

int countPal(string s, int i, int j, int *count) {
    if (i < j) {
    	if (i+1 == j) {
    		return s[i]==s[j];
    	}
    	//check if palindrome
    	if (checkPal(s, i, j)) {
    		*count+=1;
    		return countPal(s, i+1, j, count) + countPal(s, i, j-1, count) + 1 - countPal(s, i+1, j-1, count);
    		//return 1;
    	} else {
    		return countPal(s, i+1, j, count) + countPal(s, i, j-1, count) - countPal(s, i+1, j-1, count);
    	}
    }
    return 0;
}

int main() {
	int num_tc = 0;
	cin>>num_tc;
	if (num_tc < 1 || num_tc > 100)
	{
		cout<<"Invalid tc num"<<endl;
		return 1;
	}
	int len;
	string st;
	for (int i = 0; i < num_tc; i++) {
		len = 0;
		cin>>len;
		if (len < 2 || len > 500) {
			cout<<"Invalid str len"<<endl;
			return 1;
		}
        cin>>st;
        int count = 0;
        int out = 0;
        out = countPal(st, 0, len-1, &count);
        cout<<out<<endl;
	}
	return 0;
}

