#include <iostream>
using namespace std;
/*You are required to complete this function */
int remove_duplicate(int [],int );
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int a[N];
        for(int i=0;i<N;i++)
        {
            cin>>a[i];
        }
    int n = remove_duplicate(a,sizeof(a)/sizeof(a[0]));
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    }
}


/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*You are required to complete this function */
int remove_duplicate(int A[],int N)
{
//Your code here
   /* int i;
    int num = A[0];
    int ins_ind = -1;
    int size;
    int mod_N = N;
    int corner = 0;
    for (i = 1; i < mod_N; i++) {
        if (num == A[i]) {
            ins_ind = i;
            if (i+1 == mod_N) {
                corner = 1;
            }
        } else {
            num = A[i];
            if (ins_ind != -1) {
                size = mod_N;
                for (int j = ins_ind+1; j < size; j++) {
                    A[ins_ind++] = A[j];
                }
                mod_N -= 1;
                i -= 1;
                ins_ind = -1;
            } else {
            	num = A[i];
            }
        }
    }
    return (corner? mod_N -1:mod_N);*/
	int fin =0;
	for(int i=1;i<N;++i)
		if(A[i]!=A[fin])
			A[++fin]=A[i];
	return fin+1;
}
