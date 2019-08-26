#include <iostream>

using namespace std;

int main() {
	int num_tc = 0;
	int n, i, j, ar_size, a, b, max_ind;
	//int ind;

	cin>>num_tc;
	if (num_tc < 1 || num_tc > 100) {
		cout<<"Invalid tc number, valid 1  - 100"<<endl;
		return 1;
	}

	for (n = 0; n < num_tc; n++) {
		ar_size = 0;
		cin>>ar_size;

		if (ar_size < 1 || ar_size > 10000000) {
			cout<<"Invalid array size, valid 1 - 10000000"<<endl;
			return 1;
		}

		int ar[ar_size];
		for (j = 0; j < ar_size; j++) {
			cin>>ar[j];
			if (ar[j] < 0 || ar[j] >100000000) {
		        cout<<"Invalid array elem, valid 1 - 100000000"<<endl;
		        return 1;
			}
		}

		max_ind = -1;
		/*for (a = 0; a < ar_size-1; a++) {
			ind = -1;
			for (b = a+1; b < ar_size; b++) {
				if (ar[a] <= ar[b]) {
                    if (ind < (b - a)) {
                    	ind = b - a;
                    }
				}
			}
			if (max_ind < ind) {
				max_ind = ind;
			}
		}*/
		int lmin[ar_size], rmax[ar_size];
		lmin[0] = ar[0];
		for (a = 1; a < ar_size; a++) {
            if (ar[a] < lmin[a-1]) {
            	lmin[a] = ar[a];
            } else {
            	lmin[a] = lmin[a-1];
            }
		}

		rmax[ar_size-1] = ar[ar_size-1];
		for (b = ar_size-2; b >= 0; b--) {
			if (ar[b] > rmax[b+1]) {
				rmax[b] = ar[b];
			} else {
				rmax[b] = rmax[b+1];
			}
		}

		i = 0; j = 0;
		while (i < ar_size && j < ar_size) {
			if (lmin[i] <= rmax[j]) {
				if (max_ind < (j - i)) {
					max_ind = j - i;
				}
				j++;
			} else {
				i++;
			}
		}

		cout<<max_ind<<endl;
	}

	return 0;
}
