//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
/*
https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=find_the_number_of_islands
*/
// } Driver Code Ends
class Solution {
  public:
  
    bool isNode(pair<int , int> p , int r , int c ,vector<vector<char>>& grid ){
        return ((p.first < r && p.first > -1)&&(p.second > -1 && p.second < c)) && (grid[p.first][p.second] == '1'); 
    }
    void bfs(int x ,int y ,vector<vector<char>>& grid ,vector<vector<int>>& vis , int r, int c ){
        
        queue<pair<int , int>> q;
        q.push({x, y});
        vis[x][y] = 1;
        while(!q.empty()){
            pair<int , int> p = q.front();
            q.pop();
            int x = p.first;
            int y = p.second;
            for(int dx = -1 ; dx <=1;dx++){
                for(int dy = -1 ; dy <=1 ; dy ++){
                    int nx = x + dx;
                    int ny = y + dy;
                    if(isNode({nx , ny},r,c,grid) && !vis[nx][ny]){
                        vis[nx][ny] = 1;
                        q.push({nx,ny});
                    }
                }
            }
        }
    }
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        
        int r = grid.size() , c = grid[0].size();
        int ans = 0;
        vector<vector<int>> vis(r,vector<int>(c, 0));
        for(int i = 0 ; i < r ; i++){
            for(int j = 0 ; j < c ; j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    ans ++;
                    bfs(i , j , grid , vis , r, c);
                }
            }
        }
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends