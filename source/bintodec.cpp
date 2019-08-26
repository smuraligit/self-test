/*
 * bintodec.cpp
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
	    cout<<"Invalid"<<endl;
	    return 1;
	}
	string st;
	for (int i = 0; i < num_tc; i++){
	    st = "";
	    cin>>st;
	    int pow = 1;
	    int ans = 0;
	    for (int j = (int)st.size()-1; j >=0 ; j--) {
	        if (st.at(j) == '1') {
	           ans += pow;
	        }
	        pow = pow * 2;
	    }
	    cout<<ans<<endl;
	}
	return 0;
}


