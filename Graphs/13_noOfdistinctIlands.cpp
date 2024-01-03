#include <bits/stdc++.h>
using namespace std;

//https://bit.ly/3AsA08W

class Solution {
    private :

    vector<pair<int,int>> shiftIsland(vector<pair<int,int>> island) {
        auto baseNode = island[0];

        for(auto & node : island) {
            node.first -= baseNode.first;
            node.second -= baseNode.second;
        }
        return island;
    }

    vector<pair<int,int>> bfs (int i , int j , vector<vector<int>> & grid, vector<vector<int>> & isVisited) {
            vector<pair<int,int>> island;
            int n = grid.size(), m = grid[0].size();
            int dx[] = {1,-1,0,0}, dy[] = {0,0,1,-1};
            queue<pair<int,int>> q;
            q.push({i,j});
            isVisited[i][j] = 1;

            while (q.size() != 0)
            {
               int x = q.front().first, y = q.front().second;
               island.push_back(q.front());
                q.pop();

                for (int i = 0; i < 4; i++)
                {
                    int nx = x + dx[i] , ny = y + dy[i];
                    if(nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == 1 && !isVisited[nx][ny]){
                        isVisited[nx][ny] = 1;
                        q.push({nx,ny});
                    }
                }
                
            }
            return shiftIsland(island);
            
    }
    
    
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>>isVisited(n,vector<int>(m,0));
        set<vector<pair<int,int>>> islands;

        // while writing nested loop be  careful to have correct conditions for loop
        // like dont put i in place of j
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if(grid[i][j] == 1 && !isVisited[i][j]){
                    islands.insert(bfs(i,j,grid,isVisited));
                }
            }
            
        }
        return islands.size();
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
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
