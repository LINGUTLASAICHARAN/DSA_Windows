#include <bits/stdc++.h>
using namespace std;



class Solution {
    private:
    bool dfsCheck(int node, vector<int> adj[], vector<int
    > &isVisited, vector<int> &isPathVisited, vector<int> &check )  {

        // any node that is part of a cycle is not a safe node 
    

        isVisited[node] = 1;
        isPathVisited[node] = 1;

        for(int adjNode : adj[node]) {
            if(!isVisited[adjNode]) {
                bool x = dfsCheck(adjNode, adj,isVisited,isPathVisited, check);
                if(x) {
                    // if x is true then it implies node is a part of cyce and it is marked as a non safe node and return true that there is a cycle
                    check[node] = 0;
                    return true;
                }
            }
            else if(isPathVisited[adjNode]) {
                // if the node is visited and is also path visited then it implies node is a part of cyce and it is marked as a non safe node and return true that there is a cycle
                check[node] = 0;
                return true;
            }
        }

        // if there is no cycle attached to the current node then this node is safe node and it is marked as unvisited in the path as we are returning from the function call and a new path will be taken

        check[node] = 1;
        isPathVisited[node] = 0;
        return false;
    }
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<int> isVisited(V,0), isPathVisited(V,0), check(V,0),ans;
        for (int i = 0; i < V; i++)
        {
            if(!isVisited[i]) {
                // to covert all the components and even if dfs check returns true indicating the presence of a cycle, all the calls have to be made
                dfsCheck(i,adj,isVisited,isPathVisited,check);
            }
        }
        for (int i = 0; i < V; i++)
        {

            if(check[i]) {
                // is the node is checked it is a safe node
                ans.push_back(i);
            }
        }
        
        return ans;

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
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}
