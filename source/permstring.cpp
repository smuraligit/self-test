/*
 * permstring.cpp
 *
 *  Created on: Jul 28, 2019
 *      Author: srinivasanmurali
 */

#include <iostream>

using namespace std;

static inline void swapChar(string & s, int a, int b) {
	char c;
	c = s[a];
	s[a] = s[b];
	s[b] = c;
}

void permUtil(string & s, int l, int r) {
	if (l == r)
		cout<<s<<endl;
	else {
		for (int i = l; i <= r; i++) {
			//swap s[i] and s[l]
			swapChar(s, i, l);
			permUtil(s, l+1, r);
			swapChar(s, i, l);
		}
	}
}

void printPerm(string s) {
	permUtil(s, 0, s.size() - 1);
}

int main() {
    printPerm("ABCDE");
    return 0;
}


