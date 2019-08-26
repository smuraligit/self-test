#include <iostream>
#include <string>
using namespace std;

int& fun() {
	static int x = 10;
	return x;
}

int fun1(int& x) {
	return x;
}

void swap(char* &a, char* &b) {
	char *temp = a;
	a = b;
	b = temp;
}

void swap1(string& a, string& b) {
	string temp = a;
	a = b;
	b = temp;
}

//passing array by value
void aDecay(int *arr) {
	cout<<"Size of array is "<<sizeof(arr)<<endl;
	return;
}

void pDecay(int (*arr)[5]) {
	cout<<"Size of array is "<<sizeof(arr)<<endl;
}

void refNoDecay(int (&arr)[5]) {
	cout<<"Size of array is "<<sizeof(arr)<<endl;
}

int main() {
	fun() = 30;
	cout<<fun()<<endl;
	int a = 10;
	//cout<<fun1(10)<<endl;
	cout<<fun1(a)<<endl;
	char *str1 = "RADHA";
	char *str2 = "KRSNA";
	swap(str1, str2);
	cout<<"String 1 "<<str1<<endl;
	cout<<"String 2 "<<str2<<endl;
	string st1 = "KRSNA";
	string st2 = "BALARAM";
	swap1(st1, st2);
	cout<<"St 1 "<<st1<<endl;
	cout<<"St 2 "<<st2<<endl;
	//int i = 10;
	//int *ptr = &i;
	//int& *ptr1 = ptr;

	//Following example shows, null should not be assigned to reference (causes seg fault)
	//int *ptr = NULL;
	//int &ref = *ptr;
	//cout<<ref;

	//Use references to prevent array decay (loss of type and dimension)
	int ar[] = {1, 2, 3, 4, 5};
	cout<<"Size of array in main "<<sizeof(ar)<<endl;
	aDecay(ar);
	pDecay(&ar);
	refNoDecay(ar);

	return 0;
}
