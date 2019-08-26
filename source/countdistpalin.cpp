/*
 * countdistpalin.cpp
 *
 *  Created on: Apr 20, 2019
 *      Author: srinivasanmurali
 */

#include <iostream>
#include <cstring>
#include <map>
#include <utility>
#include <iterator>
using namespace std;

int countPal(string s, int n) {
    int dp[n][n];
    int p[n][n];

    map<string, int> m;

    memset(dp, 0, sizeof(dp));
    memset(p, 0, sizeof(p));


    pair<string, int> p1;
    int i, j;
    for(i = 0; i < n; i++) {
        p[i][i] = 1;
        string st3(s, i, 1);
        if (m.find(st3) == m.end()) {
        	p1.first = st3;
        	p1.second = 1;
            m.insert(p1);
        }
    }

    for(i = 0; i < n-1; i++) {
        if (s[i] == s[i+1]) {
            p[i][i+1] = 1;
            string st2(s, i, 2);
            if (m.find(st2) == m.end()) {
            	p1.first = st2;
            	p1.second = 1;
                m.insert(p1);
            }
            dp[i][i+1] = 1;
        }
    }

    for(int gap=2; gap < n; gap++) {
        for(i = 0; i < n-gap; i++) {
            j = gap+i;
            if (s[i] == s[j] && p[i+1][j-1]) {
                p[i][j] = 1;
            }

            if (p[i][j]) {
                string st1(s, i, (j-i+1));
                if (m.find(st1) == m.end()) {
                	p1.first = st1;
                	p1.second = 1;
                    m.insert(p1);
                }
                dp[i][j] = dp[i][j-1] + dp[i+1][j] + 1 - dp[i+1][j-1];
            } else {
                dp[i][j] = dp[i][j-1] + dp[i+1][j] - dp[i+1][j-1];
            }
        }
    }

    map<string, int>::iterator it;
    int count = 0;
    for(it = m.begin(); it != m.end(); it++) {
        count++;
    }

    return count;
}

int main() {
	int num_tc = 0;
	cin>>num_tc;
	if (num_tc < 1 || num_tc > 100000)
	{
		cout<<"Invalid tc num"<<endl;
		return 1;
	}
	int len;
	string st;
	for (int i = 0; i < num_tc; i++) {
		len = 0;
		cin>>len;
		//if (len < 1 || len > 100000) {
		//	cout<<"Invalid str len"<<endl;
		//	return 1;
		//}
        cin>>st;
        int out = 0;
        out = countPal(st, len);
        cout<<out<<endl;
	}
	return 0;
}


