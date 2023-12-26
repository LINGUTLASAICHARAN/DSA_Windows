#include <bits/stdc++.h>
using namespace std;
/*https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqbEoxRmZfM3NrMFFiSjBOZVA4VVYwck5RN0kzd3xBQ3Jtc0ttMkxMWnpXbC1XZ1JwaWVIRnVWOVlLMlIwdDZ4OFM3MlZGM1o2VTUxQ3ZIbE4wZjF4U1lBdGZZZGt0QXU4cF9hbE1nMUxibEEzTW1pOUFGYmQ1QldwVHRGb2t2dmJ5dXNVdVpzVUhMeTBXdGltUkh3QQ&q=https%3A%2F%2Fbit.ly%2F3cZMJXp&v=BPlrALf1LDU*/

// } Driver Code Ends
class Solution {
    private : 
    bool hasCycle(int src, vector<int> adj[], vector<int> &isVisited) {

        queue<pair<int,int>> q;
        q.push({src,-1}); //start traversing from 0
        isVisited[src] = 1;
        // doing a BFS algorithm
        while (q.size() != 0)
        {
            int currentNode = q.front().first;
            int preNode = q.front().second;
            auto p = q.front();
            q.pop();
            for (int adjNode : adj[currentNode])
            {
                if(!isVisited[adjNode]){
                    isVisited[adjNode] = 1;
                    q.push({adjNode, currentNode});
                }
                else if(adjNode != preNode) {
                    // if an adjacent node is visited and it is not the previous node 
                    // that is means there exists another 
                    return true;
                }
            }
            
        }
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        
       vector<int> isVisited(V, 0);
        bool ans = false;
       for(int i = 0 ; i < V; i++) { 
        // make sure to visit all nodes since the graph can be disconnected
        // and it is possible to miss existing cycles in graph
        if(!isVisited[i]) {
            ans = ans || hasCycle(i, adj, isVisited);
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
