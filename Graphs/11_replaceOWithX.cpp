#include <bits/stdc++.h>
using namespace std;

//https://bit.ly/3QyPr5g


class Solution{

    private :

  vector<pair<int,int>> bfs(vector<vector<int>> &isVisited, int i,int j, vector<vector<char>>mat, int n, int m) {
    vector<pair<int,int>> ans;
    queue<pair<int,int>> q;
    q.push({i,j});
    isVisited[i][j] = 1;    
    int dx []= {1,-1,0,0};
    int dy []= {0,0,1,-1};
    while (q.size() != 0)
    {
        ans.push_back(q.front());
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (int s = 0; s < 4; s++)
        {
            int nx = r + dx[s] , ny = c + dy[s];
            // always check the validity of the point first
            if( nx < n && nx >=0 && ny < m && ny >=0 && mat[nx][ny] == 'O' && !isVisited[nx][ny]) {
                isVisited[nx][ny] = 1;
                q.push({nx,ny});
            }
        }
    }
    return ans;
   }

public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<char>> ans = mat;
        vector<vector<pair<int,int>>> groups;
        vector<vector<int>> isVisited(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++)
        {
            for(int j = 0; j < m ; j++) {
                if(mat[i][j] == 'O' && !isVisited[i][j]) {
                    groups.push_back(bfs(isVisited, i,j, mat,n,m));
                }
            }
        }

        for( auto group : groups) {
            
            bool isInside = true;
            for(auto p : group) {
                // always be careful when writing big conitions in if 
                isInside = isInside && (p.first != n-1 && p.first != 0 && p.second != 0 && p.second != m-1);
            }
            if(isInside) {
                for(auto p : group){
                    ans[p.first][p.second] = 'X';
                }
            }
        }

        return ans;
        
    }
};



int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++){
                cin>>mat[i][j];
            }
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
