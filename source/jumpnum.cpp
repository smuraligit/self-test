#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
	/*int num_tc = 0;
	int i, j, x, quo, cur, prev, diff;
	cin>>num_tc;
	if (num_tc < 0 || num_tc > 100) {
		cout<<"Invalid tc num, valid 1 - 100"<<endl;
		return 1;
	}
    for (i = 0; i < num_tc; i++) {
    	x = 0;
    	cin>>x;
    	if (x < 1 || x > 1000000000) {
    		cout<<"invalid num, valid 1 - 10^9"<<endl;
    		return 1;
    	}
    	quo = -1;
        for (j = 0; j <= x; j++) {
        	diff = 0;
        	quo = j / 10;
        	cur = j % 10;

        	while (quo > 0) {
        		prev = cur;
        		cur = quo % 10;
        		if (cur > prev) {
        			diff = cur - prev;
        			if (diff > 1) {
        				break;
        			}
        		} else if (prev > cur) {
        			diff = prev - cur;
        			if (diff > 1) {
        				break;
        			}
        		} else {
        			diff = -1;
        			break;
        		}
                quo = quo / 10;
        	}
        	if (diff == 0 || diff == 1) {
        		cout<<j<<" ";
        	}

        }
        cout<<endl;
    }*/

	int num_tc = 0;
	int i, x, j, num, last_dig, prev, next;
	cin>>num_tc;
	if (num_tc < 0 || num_tc > 100) {
		cout<<"Invalid tc num, valid 1 - 100"<<endl;
		return 1;
	}
	for (i = 0; i < num_tc; i++) {
		x = 0;
		cin>>x;
		if (x < 1 || x > 1000000000) {
			cout<<"invalid num, valid 1 - 10^9"<<endl;
			return 1;
		}

		vector<int> out;
		queue<int> q;
		out.push_back(0);
		//cout<<"0"<<" ";

		for (j = 1; j <= 9; j++) {
			q.push(j);

			while (!q.empty()) {
				num = q.front();
				out.push_back(num);
				//cout<<num<<" ";
				q.pop();
				if (num <= x) {
                    last_dig = num % 10;
                    if (last_dig == 0) {
                    	//add next num
                        next = num * 10 + (last_dig + 1);
                        if (next <= x){
                    	    q.push(next);
                        }
                    } else if (last_dig == 9) {
                    	//add prev num
                    	prev = num * 10 + (last_dig - 1);
                    	if (prev <= x) {
                    	    q.push(prev);
                    	}
                    } else {
                    	//add both
                    	next = num * 10 + (last_dig + 1);
                    	prev = num * 10 + (last_dig - 1);
                    	if (prev <= x) {
                    		q.push(prev);
                    	}
                    	if (next <= x) {
                    		q.push(next);
                    	}

                    }
				}
			}
		}
		sort(out.begin(), out.end());
		for (j = 0; j < (int)out.size(); j++) {
			cout<<out.at(j)<<" ";
		}
		cout<<endl;

	}
	return 0;
}
