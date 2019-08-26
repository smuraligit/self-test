#include <iostream>

using namespace std;

int main() {
	int num_tc = 0;
	int i;
	int a;


	a = 0;

	cin>>num_tc;
	if (num_tc < 1 || num_tc > 110) {
		cout<<"Invalid input for test case"<<endl;
		return 1;
	}

	int arr[num_tc];

	for (i = 0; i < num_tc; i++) {
	    cin>>a;
	    if (a < 1 || a > 100) {
	    	cout<<"Invalid input for first number "<<a<<endl;
	    	return 1;
	    }
	    arr[i] = a;
	}

	for (i = 0; i < num_tc; i++) {
        if (arr[i] < 5) {
        	cout<<"Less than 5"<<endl;
        } else if(arr[i] > 5) {
        	cout<<"Greater than 5"<<endl;
        } else {
        	cout<<"Equal to 5"<<endl;
        }
	}
	return 0;
}
