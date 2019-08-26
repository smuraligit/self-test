#include <iostream>

using namespace std;

/*void markRowZeros(int (&arr), int row, int size) {
	int i;
	for(i = 0; i < size; i++) {
		arr[row][i] = 0;
	}
}

void markColZeros(int (&arr), int col, int size) {
	int i;
	for(i = 0; i < size; i++) {
		arr[i][col] = 0;
	}
}*/

int main() {
	int tc_num = 0;
	int i, a, b, arr_size, elem, ind;

	cin>>tc_num;
	if (tc_num < 1 || tc_num > 110) {
		cout<<"Invalid tc num, valid 1 - 110"<<endl;
		return 1;
	}
    for(i = 0; i < tc_num; i++) {
        arr_size = 0;
        cin>>arr_size;
        if (arr_size < 1 || arr_size > 100) {
        	cout<<"Invalid arr size, valid 1 - 100"<<endl;
        	return 1;
        }
        int arr[arr_size][arr_size];

        for (a = 0; a < arr_size; a++) {
        	for (b = 0; b < arr_size; b++) {
        		arr[a][b] = -1;
        	}
        }

        for(a = 0; a < arr_size; a++) {
            for(b = 0; b < arr_size; b++){
                elem = 0;
                cin>>elem;
                if (elem < 0 || elem > 1000) {
                	cout<<"Invalid elem, valid 1 - 1000"<<endl;
                	return 1;
                }
                if (elem == 0 && arr[a][b] == -1) {
                    //markRowZeros(arr[a], a, arr_size);
                    //markColZeros(arr, b, arr_size);
                	for(ind = 0; ind < arr_size; ind++) {
                		arr[a][ind] = 0;
                		arr[ind][b] = 0;
                	}
                	//for(ind = 0; ind < arr_size; ind++) {
                	//	arr[ind][b] = 0;
                	//}
                } else {
                	if (arr[a][b] == -1) {
                		arr[a][b] = elem;
                	}
                }
            }
        }

        for(a = 0; a < arr_size; a++) {
        	for(b = 0; b < arr_size; b++) {
        		cout<<arr[a][b];
        		if (a != arr_size && b != arr_size) {
        			cout<<" ";
        		}
        	}
        }
        cout<<endl;
    }
	return 0;
}
