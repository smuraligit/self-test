#include <iostream>
#include <sstream>

using namespace std;

int main() {
	string tc_str = "";
	int num_tc = 0;
	int i;
	int a, b;

	a = b = 0;

	getline(cin, tc_str);
    if (tc_str == "") {
    	cout<<"Empty test case string"<<endl;
    	return 1;
    }

    stringstream ss(tc_str);
    ss>>num_tc;
    if (num_tc < 1 || num_tc > 100) {
    	cout<<"Invalid test case number"<<endl;
    	return 1;
    }

    int arr[num_tc][2];

    for (i = 0;  i < num_tc; i++) {
    	cin>>a>>b;
    	if (a < 1 || a > 1000) {
    		cout<<"Invalid first integer"<<a<<endl;
    		return 1;
    	}
    	if (b < 1 || b > 1000) {
    		cout<<"Invalid second integer"<<b<<endl;
    		return 1;
    	}

    	arr[i][0] = a;
    	arr[i][1] = b;
    }


    for (i = 0; i < num_tc; i++) {
    	cout<<arr[i][0]+arr[i][1]<<endl;
    	cout<<((arr[i][0] > arr[i][1])?(arr[i][0] - arr[i][1]):(arr[i][1] - arr[i][0]))<<endl;
    	cout<<((arr[i][0] > arr[i][1])?(arr[i][0] / arr[i][1]):(arr[i][1] / arr[i][0]))<<endl;
    	cout<<arr[i][0] * arr[i][1]<<endl;
    }

	return 0;
}
