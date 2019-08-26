#include <iostream>
#include <vector>

using namespace std;

int main() {
	int tc_num = 0;
	int i, j, arr_size, sum, elem;
	vector <int>out;

	cin>>tc_num;
	if (tc_num < 1 || tc_num > 100) {
		cout<<"Invalid test case number. Valid values 1 - 100"<<endl;
		return 1;
	}
	for (i = 0; i < tc_num; i++) {
		arr_size = 0;
		cin>>arr_size;
        if (arr_size < 1 || arr_size > 1000) {
        	cout<<"Invalid array size. Valid values 1 - 1000"<<endl;
        	return 1;
        }
        sum = 0;
        for (j = 0; j < arr_size; j++) {
        	cin>>elem;
        	if (elem < 0 || elem > 200) {
        		cout<<"Invalid element, valid values 1 - 200"<<endl;
        		return 1;
        	}
        	sum += elem;
        }
        out.push_back(sum);
	}
	for (i = 0; i < (int)out.size(); i++) {
	    cout<<out.at(i)<<endl;
	}
	return 0;
}
