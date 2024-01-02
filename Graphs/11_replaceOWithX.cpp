#include <bits/stdc++.h>
using namespace std;

//https://bit.ly/3QyPr5g


class Solution{

    private :
    void bfs(vector<vector<int>> &isVisited, int i,int j, vector<vector<char>>mat, int n, int m) {
    queue<pair<int,int>> q;
    q.push({i,j});
    isVisited[i][j] = 1;    
    int dx []= {1,-1,0,0};
    int dy []= {0,0,1,-1};
    while (q.size() != 0)
    {
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
   }

public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<char>> ans = mat;
        vector<vector<int>> isVisited(n, vector<int>(m, 0));


        for (int i = 0; i < n; i++)
        {
            for(int j = 0; j < m ; j++) {
                if(mat[i][j] == 'O' && !isVisited[i][j] && (i == 0 || i == n-1 || j == 0 || j == m-1)) {
                    // do a bfs only if the O is in the border only these can keep a group of Os from being covered on all sides with Xs
                    bfs(isVisited, i,j, mat,n,m);
                }
            }
        }


        for (int i = 0; i < n; i++)
        {
            for(int j = 0; j < m ; j++) {
                    if(mat[i][j] == 'O' && !isVisited[i][j]) {
                        // if any O is not visited it is not connected to a O on border and hence its is itself surrounded by Xs or is a part of a group that is engulfed by X s hence marking it as X
                         ans[i][j] = 'X';
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
