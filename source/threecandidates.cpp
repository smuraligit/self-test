/*
 * threecandidates.cpp
 *
 *  Created on: Mar 28, 2019
 *      Author: srinivasanmurali
 */


#include <iostream>
using namespace std;

int main() {
	//code
	int num_tc = 0;
	int len, i, j;
	int max0, max1, max2, min0, min1;
	cin>>num_tc;
	if (num_tc < 1 || num_tc > 100) {
	    cout<<"invalid tc, valid 1-100"<<endl;
	    return 1;
	}
	for (i = 0; i < num_tc; i++) {
	    len = 0;
	    cin>>len;
	    if (len < 3 || len > 10000000) {
	        cout<<"Invalid len, valid 1-10000000"<<endl;
	        return 1;
	    }
	    int arr[len];
	    min0 = 1000000;
	    min1 = 1000000;
	    max0 = -1000000;
	    max1 = -1000000;
	    max2 = -1000000;
	    for(j = 0; j < len; j++) {
	        cin>>arr[j];
	        if (arr[j] < -100000 || arr[j] > 100000) {
	            cout<<"Invalid elem, valid -100000 to 100000"<<endl;
	            return 1;
	        }
	        if (arr[j] < min0) {
	            min1 = min0;
	            min0 = arr[j];
	        } else if (arr[j] < min1) {
	            min1 = arr[j];
	        }
	        if (arr[j] > max0) {
	            max2 = max1;
	            max1 = max0;
	            max0 = arr[j];
	        } else if(arr[j] > max1) {
	            max2 = max1;
	            max1 = arr[j];
	        } else if (arr[j] > max2) {
	            max2 = arr[j];
	        }
	    }
	    long int prod0 = max0*max1*max2;
	    long int prod1 = min0*min1*max0;
	    //if (prod0 > prod1)
	    cout<<((prod0 > prod1)?prod0:prod1);
	    cout<<endl;
	}
	return 0;
}

