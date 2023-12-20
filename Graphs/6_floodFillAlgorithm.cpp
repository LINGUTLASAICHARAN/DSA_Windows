//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
/*https://practice.geeksforgeeks.org/problems/flood-fill-algorithm1856/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=flood-fill-algorithm*/
class Solution {
public:
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        int maxRow = image.size()-1, maxCol = image[0].size()-1;
        vector<vector<int>> isVisited(maxRow+1, vector<int>(maxCol+1, 0));
        int delRow[] = {1, 0, -1, 0};
        int delCol[] = {0, 1, 0 , -1};
        int color = image[sr][sc];
        dfs(image, sr, sc, newColor, color, isVisited, maxRow,maxCol, delRow, delCol);
        return image;
    }

    void dfs(vector<vector<int>>& image, int sr, int sc, int newColor, int color,vector<vector<int>> &isVisited, int mr , int mc, int delRow[], int delCol[]){

            if(valid(sc,sr,mr,mc) && image[sr][sc] == color && !isVisited[sr][sc]){
                    isVisited[sr][sc] = 1;
                    image[sr][sc] = newColor;
					cout <<( image[sr][sc] == color )<< "  " <<  !isVisited[sr][sc];
                for(int i = 0 ; i < 4 ; i++)
                    dfs(image, sr+delRow[i], sc +delCol[i], newColor, color, isVisited, mr , mc, delRow, delCol);
            }

    }
    bool valid(int x , int y , int mr , int mc){
        return x>=0 && x<=mc && y>=0 && y<=mr;
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		// for(auto i: ans){
		// 	for(auto j: i)
		// 		cout << j << " ";
		// 	cout << "\n";
		// }
	}
	return 0;
}
// } Driver Code Ends