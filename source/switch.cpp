#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    string arr[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};
    int num_tc = 0;
    int i, num;
    vector <int>numVect;

    num = 0;

    cin>>num_tc;

    if (num_tc < 1 || num_tc > 1000) {
    	cout<<"Invalid test case number valid 1 - 1000"<<endl;
    	return 1;
    }

    for (i = 0; i < num_tc; i++) {
    	cin>>num;
    	if (num < 1 || num > 100) {
    		cout<<"Invalid number valid 1 - 100"<<endl;
    		return 1;
    	}
        numVect.push_back(num);
    }

    for (i = 0; i < (int)numVect.size(); i++) {
    	if (numVect.at(i) > 10) {
    		cout<<"not in range"<<endl;
    	} else {
    		cout<<arr[numVect.at(i)]<<endl;
    	}
    }
	return 0;
}
