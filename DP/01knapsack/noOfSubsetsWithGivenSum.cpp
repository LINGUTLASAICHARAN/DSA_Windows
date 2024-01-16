#include <bits/stdc++.h>
using namespace std;

int noOfSubSetsWithGivenSum(int arr[], int n, int sum) {

    if(sum == 0) return 1;

    if(n == 0) return 0;

    if(arr[n-1] <= sum){
        return noOfSubSetsWithGivenSum(arr,n-1,sum) + noOfSubSetsWithGivenSum(arr, n-1, sum - arr[n-1]);
    } else {
        return noOfSubSetsWithGivenSum(arr,n-1,sum);
    }
}

int main(){
    int arr [] = {2,3,5,6,8,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = 10;

    cout << "Recursive solution " << noOfSubSetsWithGivenSum(arr,n,sum) <<endl;

    int t[n+1][sum+1];

    for (int i = 0; i < n+1; i++)
    {
        for(int j = 0; j < sum+1; j++) {
            if(j == 0) {
                // 0 sum subset is always {}
                t[i][j] = 1;
            } else if(i == 0 ){
                // non zero sum and empty set 0 subsets possible
                t[i][j] = 0;
            }
        }
    }

    //  always start form non base cases other wise you will access the array in -ve indecises like t[-1][0]
    for(int no = 1; no < n+1; no++) {

        for(int s = 1; s < sum+1; s++) {
            if(arr[no-1] <= s){
                t[no][s] = t[no-1][s] + t[no-1][s-arr[no-1]];
            } else{
                t[no][s] = t[no-1][s];
            }
        }
    }
    cout <<"top down answer  " << t[n][sum] << endl;
    return 0;
}