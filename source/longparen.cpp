#include <iostream>
#include <stack>
using namespace std;

int main() {
	int tc_num = 0;
	//int i, j, max_len, lvl, max_lvl, accum_len;
	int i;

	cin>>tc_num;
	if (tc_num < 1 || tc_num > 500) {
		cout<<"Invalid tc num, valid 1 - 500"<<endl;
		return 1;
	}

	/*for (i = 0; i < tc_num; i++) {
		max_len = 0;
		lvl = 0;
		max_lvl = 0;
		accum_len = 0;
		string st;

		stack<char> stack_ch;
		cin>>st;
		if (st.length() > 100000) {
			cout<<"Invalid string len, valid 1 - 10^5"<<endl;
			return 1;
		}
		int len[st.length()];
		for (j = 0; j < (int)st.length(); j++) {
			len[j] = 0;
		}
        for (j = 0; j < (int)st.length(); j++) {
        	if (st.at(j) != '\0') {
        		if (st.at(j) == '(') {
        			stack_ch.push(st.at(j));
        			if (len[lvl] % 2 != 0) {
        				lvl++;
        				if (max_lvl < lvl) {
        					max_lvl = lvl;
        				}
        			}
        			len[lvl] += 1;
        		} else if (st.at(j) == ')') {
        			if (!stack_ch.empty()) {
        				stack_ch.pop();
        				if (len[lvl] % 2 == 0) {
        					lvl--;
        				}
        				len[lvl] += 1;
        			}
        		}
        	}
        }
        for (j = 0;  j <= max_lvl; j++) {
        	if (len[j] % 2 != 0) {
        		len[j] -= 1;
        		if (max_len <= len[j]) {
        			max_len = len[j];
        		}
        		accum_len = 0;
        	} else {
        		if (accum_len) {
                    int tmp_len = max_len + len[j];
                    if (max_len <= tmp_len) {
                    	max_len = tmp_len;
                    }
        		} else {
        			if (max_len <= len[j]) {
        				max_len = len[j];
        			}
        		}
        		accum_len = 1;
        	}
        }
        cout<<max_len<<endl;
	}*/

	for (i = 0 ; i < tc_num; i++) {
		string st;
		int j;
		int max_len = 0;
		cin>>st;

		if (st.length() > 100000) {
			cout<<"Invalid string len, valid 1 - 10^5"<<endl;
			return 1;
		}
		int n = st.length();

		stack<int> stk_int;
		stk_int.push(-1);

		for (j = 0; j < n; j++) {
			if (st[j] == '(') {

				stk_int.push(j);
			} else {
				stk_int.pop();

				if (!stk_int.empty()) {
                    max_len = max(max_len, j - stk_int.top());

				} else {
					stk_int.push(j);
				}
			}
		}
		cout<<max_len<<endl;

	}
	return 0;
}
