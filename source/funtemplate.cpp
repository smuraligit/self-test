#include <iostream>
using namespace std;

template <typename T>
T returnMax(T x, T y) {
	return ((x > y)? x : y);
}

template <typename T>
void printArray(T a[], int n) {
	for (int i = 0; i < n; i++) {
		cout<<a[i]<<endl;
	}
	return;
}

int main() {
	cout <<"Max of 4 and 6 is "<<returnMax<int>(4, 6)<<endl;
	cout<<"Max of 5.4 and 4.5 is "<<returnMax<double>(5.4, 4.5)<<endl;
	int arr[] = {1.0, 2.3, 3.5, 4.7, 5.8};
	printArray<int>(arr, 5);
	return 0;
}
