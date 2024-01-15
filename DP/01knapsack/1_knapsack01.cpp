#include <bits/stdc++.h>
using namespace std;

// normal recursive function
int maxFill(int profits[],int weights[], int N, int Capacity) {
    // base case if there is no capacity or weights to pick from the answer is 0
    if(Capacity == 0 || N == 0) return 0;

    // now we can choose to pick the nth weight or not

    // it is possible to pick the nth weight only if there is enough capacity
    if(Capacity >= weights[N-1]) {
        // now retunn the max of pick and not pick answers
        return max(maxFill(profits, weights, N-1 , Capacity), profits\
        [N-1]+maxFill(profits, weights, N-1, Capacity - weights[N-1]));
    }
    // if it is not possibe to pick the nth weight just return the answer with out it
    return maxFill(profits, weights, N-1, Capacity);
}


int memoize (int profits[], int weights[], int N, int Capacity, vector<vector<int>> & mem) {

    if(mem[N][Capacity] != -1) return mem[N][Capacity];

    if(Capacity == 0 || N == 0) return mem[N][Capacity] = 0;

    if(Capacity >= weights[N-1]) {
        return mem[N][Capacity] = max(memoize(profits,weights,N-1,Capacity, mem),
        profits[N-1]+memoize(profits,weights,N-1,Capacity - weights[N-1], mem) );
    }

    return mem[N][Capacity] = memoize(profits,weights,N-1,Capacity, mem);
}


// memoised function
int maxFillMemoized(int profits[], int weights[], int N, int Capacity) {
    // the only variables are N (0 to N) and Capacity (0 to Capacity)
    vector<vector<int>> mem(N+1, vector<int>(Capacity+1, -1));

    return memoize(profits, weights, N, Capacity, mem);
}


int main() {
    int profits[] = { 60, 100, 120, 500 }; 
    int weights[] = { 10, 20, 30, 22}; 
    int N = sizeof(weights) / sizeof(weights[0]);
    int Capacity = 22;

    cout << maxFill(profits,weights, N, Capacity) <<endl;
    cout << maxFillMemoized(profits, weights, N, Capacity) << endl;


    // dp
    
    // since the only variables are capacity and problem size n we need to have storage to each corresponding tuple (n, cap) each varying from 0 to max value
    vector<vector<int>> dp(N+1, vector<int>(Capacity+1));

    for (int i = 0; i < N+1; i++)
    {
        for (int j = 0; j < Capacity+1; j++)
        {
            // filling the base cases 
            if(i == 0 || j == 0) dp[i][j] = 0;
        }
        
    }
    
    // solving non base cases
    for (int n = 1; n < N+1; n++)
    {
        for (int cap = 1; cap < Capacity+1; cap++)
        {
            // now this is function call to fun(n,cap)
            // just repeat the function body by replacing 
            if(cap >= weights[n-1]) {
                dp[n][cap] = max(dp[n-1][cap], profits[n-1]+dp[n-1][cap-weights[n-1]]);
            } else {
                dp[n][cap] = dp[n-1][cap];
            }
        }
        
    }
    
    cout << dp[N][Capacity] <<endl;
    return 0;
}