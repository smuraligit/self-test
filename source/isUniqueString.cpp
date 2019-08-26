/*
 * isUniqueString.cpp
 *
 *  Created on: Jul 17, 2019
 *      Author: srinivasanmurali
 */

#include <iostream>
#include <algorithm>
using namespace std;

bool isCharUnique(string s) {
	bool charArray[256] = {0};
	int charInd;
	transform(s.begin(), s.end(), s.begin(), ::tolower);
	for (int ind = 0; ind < (int)s.size(); ind++) {
		charInd = s[ind];
		if (charArray[charInd]) {
			return false;
		} else {
			charArray[charInd] = 1;
		}
	}
	return true;
}

string revString(string s) {
	int first = 0;
	if (s.size() == 0) {
		return NULL;
	}
	int second = (int)s.size() - 1;
	int charVar;
	for (; first < second; first++, second--) {
		if (s[first] && s[second]) {
			charVar = s[second];
			s[second] = s[first];
			s[first] = charVar;
		}
	}
	return s;
}

int main() {
	string inp;
	cin>>inp;
	cout<<isCharUnique(inp)<<endl;
	cout<<revString(inp)<<endl;
	return 0;
}

