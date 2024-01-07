#include <bits/stdc++.h>
using namespace std;

//  https://bit.ly/3QwPVsi
class Solution {
  public:

  bool hasCycle (vector<int> adj[], vector<int> & isVisited, int node, vector<int> &isTraversed) {

        bool ans ;
        // mng marking the current node as visited and is also traversed in the same path
        isVisited[node] = isTraversed[node] = 1;

        // traversing the adjacent nodes
        for(int adjNode : adj[node]) {
            if(!isVisited[adjNode]) {
                // if not visited call dfs again
                ans = hasCycle(adj, isVisited, adjNode, isTraversed);
                if(ans) {
                    // if a cycle is reported then return true
                    return true;
                }
            }
            else if(isTraversed[adjNode]) {
                // here it is not required to check if the adjacent node is not equal to previous node in the path, because if prevNode = adjNode then there is a cycle between two nodes as this is a directed graph 1 ------> 2  and 2 -----> 1  
                
                // if an adjacent node is visited and it is also traversed in the same path
                // return true as this means a cycle has been found
                return true;
            }
        }
        // if no cycle is found return false and mark the node for which dfs is called as not traversed along the path as we are tracking bach from this node and going to take another path
        isTraversed[node] = 0;
        return false;


  }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
            vector<int> isVisited(V, 0);
            vector<int> isTravered(V,0);

            for(int i = 0; i < V; i++) {
                bool ans;
                if(!isVisited[i] ) {
                    ans = hasCycle(adj, isVisited, i, isTravered);
                    if(ans) {
                        return true;
                    }
                }
            }
            return false;
    }
};


int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
