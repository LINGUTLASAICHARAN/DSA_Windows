//{ Driver Code Starts
/*
https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=dfs_of_graph
*/ 
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    
  public:
    // Function to return a list containing the DFS traversal of the graph.
    // recursive function to do dfs
    void dfs(int vis[] , vector<int> adj[] , vector<int> & ans , int start){
        
        vis[start] = 1; 
        ans.push_back(start); // mark the starting vertex as visited 
        for(auto it : adj[start]){
            if(!vis[it]){ //call dfs on connected vertices only if they are not visited yet
                dfs(vis , adj , ans , it);
            }
        }
        
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        int vis[V] = {0};
        
        int start = 0;
        vector<int> ans;
        dfs(vis , adj , ans , 0);
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends