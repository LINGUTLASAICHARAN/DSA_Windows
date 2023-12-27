//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqbF9UdWFoMVRvbVBxMFFYaDVLaF9uUi1penpiQXxBQ3Jtc0tsSllQbzlWTHRsbDhpSWdEeVpObFNxd3hDTjJSMUVGamlfcEpEUnFrT2RGN1FlVkU2NUphYUpMNFp4aUlWOHlLMVY3bmZ0a2FnRm0tR0NPVWJELS1ma01LcUNyTWRSNVM5NGRoQjJJazJBNF9JYXZlVQ&q=https%3A%2F%2Fbit.ly%2F3Cc8jlW&v=edXdVwkYHF8

// } Driver Code Ends
class Solution 
{

    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int n = grid.size();
	    int m = grid[0].size();
	    vector<vector<int>> ans(n, vector<int>(m, 0));
	    vector<vector<int>> isVisited(n, vector<int>(m, 0));

        queue<pair<pair<int,int>,int>> q;

        for (int i = 0; i < n; i++)
        {
           for (int j = 0; j < m; j++)
           {
                if(grid[i][j] == 1){
                    q.push({{i,j},0});
                    isVisited[i][j] = 1;
                }
           }
           
        }
        int dx [] = {1,-1,0,0};
        int dy [] = {0,0,1,-1};
        
        while(q.size() != 0)
        {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int d = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if((nx < n && nx >= 0) && (ny >= 0 && ny < m) && !isVisited[nx][ny]){
                    q.push({{nx,ny},d+1});
                    ans[nx][ny] = d+1;
                    isVisited[nx][ny] = 1;
                }
            }
            
        }
        return ans;

	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends