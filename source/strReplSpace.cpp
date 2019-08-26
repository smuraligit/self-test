/*
 * strReplSpace.cpp
 *
 *  Created on: Aug 12, 2019
 *      Author: srinivasanmurali
 */

#include <iostream>

using namespace std;

void strReplSpace(string & in, string & out) {
	int i, j;

	if (in.empty()) {
		cout<<"Input string empty"<<endl;
		return;
	}

	for(i = 0, j = 0; i < (int)in.size(); i++) {
		if (32 == (int)in[i]) {
			out[j++] = '%';
			out[j++] = '2';
			out[j++] = '0';
		} else {
			out[j++] = in[i];
		}
	}
	return;
}

int main() {
	//string s1 = "Hello World";
	string s1 = "";
	getline(cin, s1);
	cout<<"Entered string "<<s1<<endl;

	int i, numSpace;

	for(i = 0, numSpace = 0; i < (int)s1.size(); i++) {
		if ((int) s1[i] == 32) {
			numSpace++;
		}
	}

	const int s2Size = (int)s1.size() + (numSpace * 3);
	string s2;
	cout<<"Size of s1 "<<(int)s1.size()<<endl;
	cout<<"Resizing s2 to "<<s2Size<<endl;
	s2.resize(s2Size);
	strReplSpace(s1, s2);
	cout<<s2<<endl;
	return 0;
}


