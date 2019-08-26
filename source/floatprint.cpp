#include <iostream>
#include <sstream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
	string num_tc_str = "";
	int num_tc = 0;
	int i;
	float num = 0.0;
	int prec = 0;
	vector<float> fp;
	vector<int> precVect;

	getline(cin, num_tc_str);
	if (num_tc_str == "") {
		cout<<"Num test case is empty"<<endl;
		return 1;
	}
	stringstream ss(num_tc_str);
	ss>>num_tc;

	if (num_tc < 1 || num_tc > 100) {
		cout<<"Allowed value is between 1 and 100"<<endl;
		return 1;
	}

	for(i = 0; i < num_tc; i++) {
		cin>>num>>prec;
		if (cin.fail()) {
			cout<<"Invalid input"<<num<<prec<<endl;
			return 1;
		}
		if (prec < 1 || prec > 20) {
			cout<<"Allowed precision value is between 1 and 20"<<endl;
			return 1;
		}
        fp.push_back(num);
        precVect.push_back(prec);
	}
	for(i = 0; i < (int)fp.size(); i++) {
		cout<<std::setprecision(precVect.at(i))<<fp.at(i)<<endl;
	}
	return 0;
}
