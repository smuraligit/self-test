#include <iostream>

using namespace std;

int main() {
	int num_tc = 0;
	int i;
	int a, b;


	a = b = 0;

	cin>>num_tc;
	if (num_tc < 1 || num_tc > 100) {
		cout<<"Invalid input for test case"<<endl;
		return 1;
	}

	int arr[num_tc][2];

	for (i = 0; i < num_tc; i++) {
	    cin>>a>>b;
	    if (a < 1 || a > 100) {
	    	cout<<"Invalid input for first number "<<a<<endl;
	    	return 1;
	    }
	    if (b < 1 || b > 100) {
	    	cout<<"Invalid input for second number "<<b<<endl;
	    	return 1;
	    }
	    arr[i][0] = a;
	    arr[i][1] = b;
	}

	for (i = 0; i < num_tc; i++) {
        if (arr[i][0] < arr[i][1]) {
        	cout<<arr[i][0]<<" is less than "<<arr[i][1]<<endl;
        } else if(arr[i][0] > arr[i][1]) {
        	cout<<arr[i][0]<<" is greater than "<<arr[i][1]<<endl;
        } else {
        	cout<<arr[i][0]<<" is equals to "<<arr[i][1]<<endl;
        }
	}
	return 0;
}
