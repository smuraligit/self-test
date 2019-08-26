/*
 * nextgreatest.cpp
 *
 *  Created on: Mar 23, 2019
 *      Author: srinivasanmurali
 */
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <iterator>
using namespace std;

int main() {
	//code
	int num_tc = 0;
	int i, j, len;
	cin>>num_tc;
	if (num_tc < 1 || num_tc > 50) {
	    cout<<"Invalid tc num, valid 1 - 50"<<endl;
	    return 1;
	}
	for (i = 0; i < num_tc; i++) {
	    len = 0;
	    cin>>len;
	    if (len < 1 || len > 100) {
	        cout<<"Invalid arr len, valid 1 - 100"<<endl;
	        return 1;
	    }
	    int A[len], copyA[len];
	    vector<pair<int, int > > v;
	    for (j = 0; j < len; j++) {
	        cin>>A[j];
	        copyA[j] = A[j];
	    }
	    sort(copyA, copyA+len);
	    for (int k = 0; k < len; k++) {
	        pair<int, int> p = make_pair(copyA[k], 1);
	        v.push_back(p);
	    }
	    vector<pair<int, int > >::iterator r;
	    int g = len - 1;

	    for(int a = 0; a < len-1; a++) {
	    	int decr = 0;
	        while (g >= 0) {
	            if (A[a] != copyA[g] || (A[a] == copyA[g] && decr == 1)) {
	                pair<int, int> p1 = v.at(g);
	                if (p1.second == 1) {
	                    cout<<copyA[g]<<" ";

	                    int b = 0;
	                    for (r = v.begin(); r != v.end(); ++r, b++) {
	                        pair<int, int> p2 = *r;
	                        if (p2.first == A[a] && p2.second == 1) {
	                        	if (decr == 0) {
	                        		p2.second = -1;
	                        		v[b] = p2;
	                        		break;
	                        	}
	                        } else {
	                        	if (p2.first == A[a] && p2.second == 0) {
	                        		if (decr == 1) {
	                        			p2.second = -1;
	                        			v[b] = p2;
	                        			decr = 0;
	                        			break;
	                        		}
	                        	}
	                        }
	                    }
	                    break;
	                }
	            } else {
	            	if (v[g].second > 0 && (decr == 0)) {
	            		v[g].second -= 1;
	            		decr = 1;
	            	}
	            }
	            g--;
	        }
	    }
	    cout<<"-1"<<endl;
	}
	return 0;
}



