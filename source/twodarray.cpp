#include <iostream>

using namespace std;

int main() {
    int num_tc = 0;
    int i, arr_size, a, b, elem;
    cin>>num_tc;
    if (num_tc < 1 || num_tc > 100) {
    	cout<<"Invalid tc, valid 1 - 100 value is "<<num_tc<<endl;
    	return 1;
    }
    for(i = 0; i < num_tc; i++) {
        arr_size = 0;
        cin>>arr_size;
        if (arr_size < 1 || arr_size > 100) {
        	cout<<"Invalid arr size, valid 1 - 100"<<endl;
        	return 1;
        }
        int arr[arr_size][arr_size];
        for(a = 0; a < arr_size; a++) {
        	for(b = 0; b < arr_size; b++) {
        		elem = 0;
        		cin>>elem;
        		if (elem < 0 || elem > 1000) {
        			cout<<"Invalid elem, valid 1 - 1000"<<endl;
        			return 1;
        		}
        		arr[b][a] = elem;
        	}
        }
        for(a = 0; a < arr_size; a++) {
        	for(b = 0; b < arr_size; b++) {
        		cout<<arr[a][b];
        		if (a != arr_size && b != arr_size) {
        			cout<<" ";
        		}
        	}
        }
        cout<<endl;
    }
	return 0;
}
