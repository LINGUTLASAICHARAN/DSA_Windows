#include <bits/stdc++.h>
using namespace std;

// this function returns true when there is a subset with given sum
bool isSubsetWithGivenSumPresent(int values [], int sum, int n) {

    // base case
    if(sum == 0){
        // always an empty subset exists whose sum is 0
        return true;
    }
    else if(n == 0) {
        // non zero sum and there are no elements to choose from
        return false;
    }

    if(sum >= values[n-1]) {
        return isSubsetWithGivenSumPresent(values, sum - values[n-1], n-1) || isSubsetWithGivenSumPresent(values, sum, n-1);
    }
    else{
        return isSubsetWithGivenSumPresent(values, sum, n-1);
    }
}

int main(){
    // assuming the values in the set are always positive
    int values[] = {2,3,7,8,10};
    int sum = 10;
    int n = sizeof(values)/sizeof(values[0]);
    // similarity with knapsack
    // max value is capacity in knapsack and sum here
    // there were stones to choose from and here we have elements
    cout << "recursion solutio  "<<isSubsetWithGivenSumPresent(values, sum, n) <<endl;

    //dp
    bool t[n+1][sum+1]; // table to store answer

    for (int i = 0; i < n+1; i++)
    {
        for(int j = 0; j < sum+1 ; j++) {
            // if the required sum is 0 empty subset
            if(j == 0) {
                t[i][j] = true;
            }
            else if(i == 0) {
                // if nonzero sum is needed and there are no elements to choose from it is false
                t[i][j] = false;
            }
    }
    }
    
    for(int no = 1 ; no < n+1; no++) {
        for(int s = 1; s < sum+1; s++){
            // probelm with n and s as input
            if(s >= values[no-1]) {
                t[no][s] = t[no-1][s] || t[no-1][s-values[no-1]];
            }
            else {
                t[no][s] = t[no-1][s];
            }

        }
    }

    cout <<"Top down solution  " << t[n][sum];
    return 0;
}