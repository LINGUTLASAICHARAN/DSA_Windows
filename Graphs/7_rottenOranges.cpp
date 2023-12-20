//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
/*https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqbFF6eTFPS05FTlplVWgtOE44NlRtM2JYczZZd3xBQ3Jtc0trUWxqSW9odG5ubnpuZXlwWjhNTFpiSXFEc0d1Unp4UlRjaTQ5MF9GNVVMSnlxWEk2aUEtNWNONnhfeTI3YmU0dXFaaGxLOWg0d2dfOXFfaFlrNlVVM0JNZ3hGanpWRmtaUEJtVDdvMGdJS2ltaGI3NA&q=https%3A%2F%2Fbit.ly%2F3oekoir&v=yf3oUhkvqA0*/
// } Driver Code Ends
class Solution 
{
		private:
		bool vaild(int x, int y , int mr , int mc){
		return x >=0 && x < mr && y >=0 && y <mc;
	}
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
    int maxRow = grid.size();
		int maxCol = grid[0].size();
		int maxTime = 0;
		queue<pair<int,pair<int,int>>> q;
		int dx[] = {1,0,-1,0};
		int dy[] = {0,-1,0,1};
		for(int i = 0; i< maxRow ; i++){
			for (int j = 0; j < maxCol; j++)
			{
				if(grid[i][j] == 2) {q.push({0,{i,j}});
}
			}
		}

		while (!q.empty())
		{
			auto p = q.front();
			int x = p.second.first;
			int y = p.second.second;
			int t = p.first;
			q.pop();
			for (int i = 0; i < 4; i++)
			{
				int nx = x+dx[i], ny = y+dy[i];
				if(vaild(nx,ny,maxRow,maxCol) && grid[nx][ny] == 1 ){
					grid[nx][ny] = 2;
					q.push({t+1,{nx,ny}});
					maxTime = max(maxTime, t+1);
				}

			}
			
		}
		for(auto v : grid){
			for(int x : v)
			if(x == 1) return -1;
		}
		
		return maxTime;
		

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
		int ans = obj.orangesRotting(grid);
		cout << ans<< "\n";
	}
	return 0;
}
// } Driver Code Ends