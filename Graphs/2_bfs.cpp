#include <bits/stdc++.h>
#include<queue>
using namespace std;
// gfg link https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=bfs_of_graph
// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> isVisited(V, 0); // vector size V and initialize with 0
        vector<int> ans;
        queue<int> q;
        q.push(0);
        isVisited[0] =1;
        while(!q.empty()){
            int x = q.front();
            ans.push_back(x);
            q.pop();
            for(auto it : adj[x]){
                if(!isVisited[it]){
                    q.push(it);
                    isVisited[it] = 1; // mark it as visited when pushing into the queue
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
        int V, E;
        cin >> V >>E;

        vector<int> adj[V]; //adjacency matrix

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends