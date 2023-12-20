//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
/*https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqbEoxRmZfM3NrMFFiSjBOZVA4VVYwck5RN0kzd3xBQ3Jtc0ttMkxMWnpXbC1XZ1JwaWVIRnVWOVlLMlIwdDZ4OFM3MlZGM1o2VTUxQ3ZIbE4wZjF4U1lBdGZZZGt0QXU4cF9hbE1nMUxibEEzTW1pOUFGYmQ1QldwVHRGb2t2dmJ5dXNVdVpzVUhMeTBXdGltUkh3QQ&q=https%3A%2F%2Fbit.ly%2F3cZMJXp&v=BPlrALf1LDU*/
// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
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