/*
 * checkAnagram.cpp
 *
 *  Created on: Aug 8, 2019
 *      Author: srinivasanmurali
 */


#include <iostream>
#include <map>

using namespace std;

bool checkIfAnagram(string & s1, string & s2) {
	map<int, int> m;
	int i, ch;
	bool res = true;

	if (s1.empty() || s2.empty()) {
		return false;
	}

	for (i = 0; i < 256; i++) {
		m[i] = 0;
	}

	for (i = 0; i < (int) s1.size(); i++) {
		ch = tolower(s1[i]);
		m[ch]++;
	}
	for (i = 0; i < (int) s2.size(); i++) {
		ch = tolower(s2[i]);
		if (m[ch] == 0) {
			res = false;
			break;
		}
		//if (m.find(ch) != m.end()) {
		m[ch]--;
		//}
	}
	/*for (i = 0; i < 256; i++) {
		if (m[i] > 0) {
			res = false;
			break;
		}
	}*/
	return res;
}

int main() {
	string s1 = "ELVISA";
	string s2 = "LEVISC";
	cout<<checkIfAnagram(s1, s2)<<endl;
	return 0;
}


