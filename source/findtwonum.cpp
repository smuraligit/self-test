#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int tc_num = 0;
	int i, num, a;

	cin>>tc_num;
	if (tc_num < 1 || tc_num > 100) {
	    cout<<"Invalid tc num - valid 1 - 100"<<endl;
	    return 1;
	}
	for (i = 0; i < tc_num; i++) {
		vector <int>out;
	    num = 0;
	    cin>>num;
	    if (num < 1 || num > 1000000) {
	        cout<<"invalid N valid 1 - 1000000"<<endl;
	        return 1;
	    }
	    int ar[2*num + 2], aux[2*num + 2];
	    for (a = 0; a < (2*num+2); a++) {
	        cin>>ar[a];
	        //if (ar[a] < 1 || ar[a] > (5 * 10^8)) {
	        //    cout<<"invalid elem, valid 1 - 5*10^8"<<endl;
	        //    return 1;
	        //}
	        aux[a] = 1;
	    }
	    std::sort(ar, ar+(2*num+2));
	    for (a = 0; a < ((2*num + 2)-1);) {
	    	if (ar[a] != ar[a+1]) {
	    		out.push_back(ar[a]);
	    		a++;
	    	} else {
                a+=2;
	    	}
	        /*if (ar[a] == ar[a+1]) {
	            aux[a] = 0;
	            aux[a+1] = 0;
	            a+=2;
	        } else {
	            a++;
	        }*/
	    }
	    if (a == ((2 * num +2)-1)) {
	    	out.push_back(ar[a]);
	    }
	    /*for (a = 0; a < (2 * num +2); a++) {
	        if (aux[a] == 1) {
	            cout<<ar[a]<<" ";
	        }
	    }*/
	    for (a = 0; a < (int)out.size(); a++) {
            cout<<out.at(a)<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
