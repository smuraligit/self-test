#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int tc_num = 0;
    int i, arr_size, ind, j, elem;
    vector <int>out;
    cin>>tc_num;
    if (tc_num < 0|| tc_num > 10) {
    	cout<<"Invalid, valid values 1 - 10"<<endl;
    	return 1;
    }
    for (i = 0; i < tc_num; i++) {
    	vector <int> in;
        arr_size = 0;
        cin>>arr_size;
        if (arr_size < 1 || arr_size > 100) {
        	cout<<"Invalid, valid values 1 - 100"<<endl;
        	return 1;
        }
        ind = 0;
        cin>>ind;
        if (ind < 0 || ind > (arr_size - 1)) {
        	cout<<"Invalid, valid values 0 - "<<arr_size-1<<endl;
        	return 1;
        }
        for (j = 0; j < arr_size; j++) {
            elem = 0;
            cin>>elem;
            if (elem < 1 || elem > 100) {
            	cout<<"Invalid, valid values 1 - 100"<<endl;
            	return 1;
            }
            in.push_back(elem);
        }
        out.push_back(in.at(ind));
    }
    for (i = 0; i < (int)out.size(); i++) {
        cout<<out.at(i)<<endl;
    }
	return 0;
}
