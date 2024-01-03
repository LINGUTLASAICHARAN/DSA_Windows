#include <bits/stdc++.h>
using namespace std;

//https://bit.ly/3preQSc


class Solution {
    private :
    void bfs(int i , int j , vector<vector<int>> & isVisited,vector<vector<int>> &grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int,int>> q;
        isVisited[i][j] = 1;
        q.push({i,j});
        int dx [] = {1,-1,0,0};
        int dy [] = {0,0,1,-1};

        while (q.size()!=0)
        {
            int x = q.front().first, y = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i], ny = y + dy[i];
                if(nx >=0 && nx < n && ny >=0 && ny < m && !isVisited[nx][ny] && grid[nx][ny] == 1) {
                    isVisited[nx][ny] = 1;
                    q.push({nx,ny});
                }
            }
            
        }
        

    }
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> isVisited(n,vector<int>(m,0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                // be careful to use n-1 and m-1 for borders not n,m !!!
                 if(grid[i][j] == 1 && !isVisited[i][j] &&(i == 0 || j == 0 || i == n-1 || j == m-1)) {
                    // run bfs on 1s in the edges only
                    bfs(i,j,isVisited,grid);
                }
            }
            
        }

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if(grid[i][j] == 1 && !isVisited[i][j]) {
                    // if there is an unvisited 1 then it has to be counted since there is no way to reach the border of grid from these 1s
                    ans++;
                }
            }
            
        }
        
        return ans;
        
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
