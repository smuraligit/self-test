#include <iostream>
#include <vector>
using namespace std;

int main() {
	string str = "GeeksforGeeks";
	int num_tc = 0;
	int i, num;
	vector <int>numVect;

	num = 0;

	cin>>num_tc;
	if (num_tc < 1 || num_tc > 20) {
		cout<<"Invalid test case number. Valid 1 - 20"<<endl;
		return 1;
	}

	for (i = 0; i < num_tc; i++) {
		cin>>num;
		if (num < 0 || num > 100) {
			cout<<"Invalid number inp. Valid 1 - 100"<<endl;
			return 1;
		}
		numVect.push_back(num);
	}
	for (i = 0; i < (int)numVect.size(); i++) {
		for(int j = 0; j < numVect.at(i); j++) {
			cout<<str<<endl;
		}
	}
	return 0;
}
