/*
 * convertfive.cpp
 *
 *  Created on: Mar 14, 2019
 *      Author: srinivasanmurali
 */



#include <iostream>
#include <cmath>
using namespace std;
int convertFive(int n);

// Driver program to test above function
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
    	int n;
    	cin>>n;
    	cout<<convertFive(n)<<endl;
    }
}


/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*you are required to complete this method*/
int convertFive(int n)
{
//Your code here
    int i = 0;
    int out = 0;

    if (n == 0) {
        return 5;
    }
    int q = n;
    while(q) {
        int rem = q % 10;
        if (rem == 0) {
            rem = 5;
        }
        out += rem * (pow(10, i));
        i++;
        q = q / 10;
    }
    return out;
}

