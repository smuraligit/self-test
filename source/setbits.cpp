/*
 * setbits.cpp
 *
 *  Created on: Mar 28, 2019
 *      Author: srinivasanmurali
 */


#include <iostream>
using namespace std;

int main() {
	//code
	int num_tc = 0;
	cin>>num_tc;
	if (num_tc < 1 || num_tc > 100) {
	    cout<<"Invalid num tc, valid 1 - 100"<<endl;
	    return 1;
	}
	int N, count;
	for (int i = 0; i < num_tc; i++) {
	    N = 0;
	    cin>>N;
	    if (N < 1 || N > 1000000) {
	        cout<<"Invalid N, valid 1 - 10^6"<<endl;
	        return 1;
	    }
	    count = 0;
	    if (N > 1) {
	        while (N>>=1) {
	            count++;
	        }
	    } else if (N == 1) {
	    	count = 1;
	    }
	    cout<<count<<endl;
	}
	return 0;
}

