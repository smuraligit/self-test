/*
 * pfn.cpp
 *
 *  Created on: Mar 29, 2019
 *      Author: srinivasanmurali
 */

#include <iostream>
using namespace std;

void pFN(int arr[], int k, int start, int len) {
    int i;
    for (i = 0; i < k; i++) {
        if (arr[i] < 0) {
            cout<<arr[i]<<" ";
            break;
        }
    }
    if (i == k) {
        cout<<"0 ";
    }
    if (start+k < len) {
        pFN(arr+1, k, start+1, len);
    }
}

int main() {
	//code
	int num_tc = 0;
	int len;
	cin>>num_tc;
	if (num_tc < 1 || num_tc > 100000) {
	    cout<<"Invalid tc num, valid 1 - 100000"<<endl;
	    return 1;
	}
	for (int i = 0; i < num_tc; i++) {
	    len = 0;
	    cin>>len;
	    if (len < 1 || len > 100000) {
	        cout<<"Invalid len, valid 1 - 100000"<<endl;
	        return 1;
	    }
	    int arr[len];
	    for (int j = 0; j < len; j++) {
	        cin>>arr[j];
	        //if (arr[j] < 1 || arr[j] > 100000) {
	          //  cout<<"Invalid arr elem, valid 1 - 100000"<<endl;
	           // return 1;
	        //}
	    }
	    int k = 0;
	    cin>>k;
	    if (k < 1 || k > 100000) {
	        cout<<"Invalid k val, allowed 1-100000"<<endl;
	        return 1;
	    }
	    pFN(arr, k, 0, len);
	    cout<<endl;
	}
	return 0;
}


