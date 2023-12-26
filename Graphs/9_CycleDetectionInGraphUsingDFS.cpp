//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqbDNwUi1LaW51U3ZjWTVHMXU0cUFJZ0NkX3hGZ3xBQ3Jtc0tscnhSZVNneXgyZnp5RG1xQmhNcmptYXBOSnh2TlhUTHdmZ3lCeE8zdHdac2pQT3hWSTJMNjk1ZUF2c2s0NDBPR2xyMVFicWdfWVV3MFdQTGlnY0pZNkhhQmtvRVYzaDhfMmhNMDVsRnQ0UDdzNUd2Zw&q=https%3A%2F%2Fbit.ly%2F3cZMJXp&v=zQ3zgFypzX4

// } Driver Code Ends
class Solution {

private : 
    bool hasCycle(vector<int> & isVisited,  vector<int> adj[], int srcNode, int prevNode) {

        isVisited[srcNode] = 1;

        for(int adjNode : adj[srcNode]) {
            if(!isVisited[adjNode]){
                // call dfs on the adjacent node
                if(hasCycle(isVisited, adj, adjNode, srcNode )) return true;
            }
            else if( adjNode != prevNode) return true;
        }
        return false;
    }

  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        
        vector<int> isVisited(V,0);
        bool ans = false;
        for (int i = 0; i < V; i++)
        {
            if(!isVisited[i])
            ans = ans || hasCycle(isVisited, adj, i, -1);
        }
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
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends