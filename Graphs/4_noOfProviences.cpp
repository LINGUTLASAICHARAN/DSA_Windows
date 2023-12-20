//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/*https://practice.geeksforgeeks.org/problems/number-of-provinces/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number_of_provinces*/


class Solution {
  public:
  
    void bfs(int start , int vis[] , vector<vector<int>> adj , int V){
        queue<int> q;
        q.push(start);
        vis[start] = 1;       
        while(!q.empty()){
                int x= q.front();
                q.pop();
                for(int j = 0 ; j < V ; j++){
                        if(adj[x][j] && !vis[j]){
                            q.push(j);
                            vis[j] = 1;
                        }
                }
        }
    }
    
    
    int numProvinces(vector<vector<int>> adj, int V) {
        int start = 0;
        int vis[V] = {0};
        int ans = 0;
        for(int i = 0; i< V ; i++){
            
            if(!vis[i]){
                ans++;
                bfs(i ,vis , adj , V);
                
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends