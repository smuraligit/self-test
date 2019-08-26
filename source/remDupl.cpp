/*
 * remDupl.cpp
 *
 *  Created on: Jul 19, 2019
 *      Author: srinivasanmurali
 */


#include <iostream>
#include <cstring>
using namespace std;

void remDuplChar(char * s) {
    int len = strlen(s);
    //char *s = s_inp.c_str();
    int bitVector[8];
    memset(bitVector, 0, sizeof(int) * 8);
    int charVar = 0;
    int i, j, ind, bitPos;
    for(i = 0; (i < len) && s[i]; i++) {
    	charVar = s[i] - '0';
        ind = charVar / 32;
        if (ind > 7) {
        	cout<<"Invalid index"<<endl;
        	return;
        }
        bitPos = charVar % 8;
        if (bitVector[ind] & (1 << bitPos)) {
        	//Duplicate
        	s[i] = '#';
        } else {
        	//set bit
        	bitVector[ind] |= 1<<bitPos;
        }
    }
    for (i = 0, j = 0; i < len && s[i]; i++) {
    	if (s[i] != '#'){
    		if (i > j) {
    			s[j] = s[i];
    		}
    		j++;
    	}
    }
    s[j] = '\0';
    cout<<"Processed string is "<<s<<endl;
}

int main() {
	string inp;
	//char *inp = NULL;
	cin>>inp;
	if (inp.empty()) {
		cout<<"Input string is empty"<<endl;
		return 1;
	}
	char * s = new char[inp.length()+1];
	strcpy(s, inp.c_str());
	remDuplChar(s);
	cout<<s<<endl;
}

