/*
 * decode.cpp
 *
 *  Created on: Apr 3, 2019
 *      Author: srinivasanmurali
 */

#include <iostream>
#include <utility>
#include <vector>
using namespace std;

void printDecodeN(int N) {
    int start = 1;
    int ind;
    vector<int> v;
    vector<int> out;
    for(int i = 1; i < N; i++) {
    	if (i == 1) {
    	    v.push_back(1);
    	    v.push_back(1);
    	    out = v;
    	} else {
    		//v contains elems to process
    		if (!v.empty()) {
    			out.clear();
    			int count = 0;
    			int prev = v.at(0);
    			for (ind = 0; ind < (int)v.size(); ind++) {
                    if (prev != v.at(ind)) {
                    	//add elem to out vector
                    	out.push_back(count);
                    	out.push_back(prev);
                    	count = 0;
                    }
                    count++;
                    prev = v.at(ind);
    			}
    			if (count > 0) {
    				out.push_back(count);
    				out.push_back(prev);
    				count = 0;
    			}
    			v.clear();
    			v = out;
    		}
    	}
    }
    if (N == 1) {
    	cout<<start<<endl;
    } else {
    	for (ind = 0; ind  < (int)out.size(); ind++) {
    		cout<<out.at(ind);
    	}
        cout<<endl;
    }
    return;
}

int main() {
	//code
	int num_tc = 0;
	int n;
	cin>>num_tc;
	if (num_tc < 1 || num_tc > 20) {
	    cout<<"Invalid tc, valid 1 - 20"<<endl;
	    return 1;
	}
	for (int i = 0; i < num_tc; i++) {
	    n = 0;
	    cin>>n;
	    if (n < 1 || n > 20) {
	        cout<<"Invalid n, valid 1 - 20"<<endl;
	        return 1;
	    }
	    printDecodeN(n);
	}
	return 0;
}


