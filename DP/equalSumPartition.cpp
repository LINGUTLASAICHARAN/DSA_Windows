#include <bits/stdc++.h>
using namespace std;

bool isEqualSumPartitionPossible(int arr [], int n) {

        int sum = 0;
        for (int i = 0; i < n; i++)
        {
           sum += arr[i];
        }
        if(sum %2 != 0) {
            // if the total sum is not even the it is not possibe for equal sum partition
            return false;
        }
        // if total sum is even then find if a subset with sum of elements = sum/2 exists where sum is value of total sum

        sum = sum /2;

        bool t[n+1][sum+1];

        for (int i = 0; i < n+1; i++)
        {
            for(int j = 0; j < sum+1 ; j++) {
                if(j == 0) { // 0 sum always possible
                    t[i][j] = true;
                }
                else if(i == 0) { // no zero sum with 0 elements not possible
                    t[i][j] = false;
                }
            }
        }

        // solving non base cases
        for(int no = 1; no < n+1 ; no ++){
            for(int s = 1; s < sum +1 ; s++){

                if(arr[no-1] <= s) {
                    t[no][s] = t[no-1][s] || t[no-1][s-arr[no-1]];
                } else {
                    t[no][s] = t[no-1][s];
                }
            }
        }
        
        return t[n][sum];
}

int main(){
    int arr[] = {1, 5, 222, 5,1};

    int n = sizeof(arr)/sizeof(arr[0]);

    // tell if it is possible to partition set into two disjoint subsets with same sum
    cout <<isEqualSumPartitionPossible(arr,n) <<endl;
    return 0;
}