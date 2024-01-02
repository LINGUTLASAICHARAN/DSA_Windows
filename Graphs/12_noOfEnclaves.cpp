#include <bits/stdc++.h>
using namespace std;

//https://bit.ly/3preQSc


class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
    }
};




int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
