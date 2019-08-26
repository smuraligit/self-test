
#include <bits/stdc++.h>
using namespace std;
void convertToRoman(int ) ;
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int N;
		cin>>N;

	convertToRoman(N);
	cout<<endl;

	}
	return 0;
}


/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

void findRomanNo(int num, string & st) {
    if (num == 0) {
        return;
    }
    if (num >= 1 && num < 4) {
        num-=1;
        st += "I";
        return findRomanNo(num, st);
    }
    if (num == 4) {
        num-=4;
        st += "IV";
        return findRomanNo(num, st);
    }
    if (num >= 5 && num < 9) {
        num-= 5;
        st += "V";
        return findRomanNo(num, st);
    }
    if (num == 9) {
        num-=9;
        st += "IX";
        return findRomanNo(num, st);
    }
    if (num > 9 && num < 40) {
        num-=10;
        st += "X";
        return findRomanNo(num, st);
    }
    if (num >= 40 && num < 50) {
        num-=40;
        st += "XL";
        return findRomanNo(num, st);
    }
    if (num >= 50 && num < 90) {
        num-=50;
        st += "L";
        return findRomanNo(num, st);
    }
    if (num >= 90 && num < 100) {
        num-=90;
        st += "XC";
        return findRomanNo(num, st);
    }
    if (num >= 100 && num < 400) {
        num-=100;
        st += "C";
        return findRomanNo(num, st);
    }
    if (num >= 400 && num < 500) {
        num-=400;
        st += "CD";
        return findRomanNo(num, st);
    }
    if (num >= 500 && num < 900) {
        num -= 500;
        st += "D";
        return findRomanNo(num, st);
    }
    if (num >= 900 && num < 1000) {
        num -= 900;
        st += "CM";
        return findRomanNo(num, st);
    }
    if (num >= 1000 && num < 5000) {
        num -= 1000;
        st += "M";
        return findRomanNo(num, st);
    }
    return;
}

/*you are required to complete
this function*/
void convertToRoman(int n)
{
//Your code here
    int n_tmp = n;
    int digits[5];
    int ind = 0;
    while(n_tmp) {
        digits[ind++] = n_tmp % 10;
        n_tmp /= 10;
    }
    int pow, num;
    string st = "";
    for (int i = ind-1; i >= 0; i--) {
        pow = 1;
        for (int j = 0; j < i; j++) {
            pow *= 10;
        }
        num = digits[i] * pow;
        findRomanNo(num, st);
    }
    cout<<st<<endl;
}
