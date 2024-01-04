
#include <bits/stdc++.h>
using namespace std;
// https://bit.ly/3SQQgId

class Solution
{
private:
    bool doColor(int i, vector<int> &colors, vector<int> adj[], int color)
    {
        bool ans ;
        colors[i] = color ; // color it with provided color

        for(auto adjNode : adj[i]) {
            if(colors[adjNode] == -1) {
                ans = doColor(adjNode, colors, adj, !color);
                // if you get false from any function call then return false
                if(!ans) return false;
            }
            else if(colors[i] == colors[adjNode]) {
                return false;
            }
        }
        return true;
    }

public:
    bool isBipartite(int V, vector<int> adj[])
    {
        // when a graph is not biparatite then it surely has a cycle with odd number of nodes in it 
        vector<int> colors(V, -1);

        for (int i = 0; i < V; i++)
        {
            bool ans;
            if (colors[i] == -1)
            {
                ans = doColor(i, colors, adj, 0); // start coloring with 0
            }
            if (!ans)
            {
                // if any part of graph is not 2 colorable the whole graph is not bi patatite
                return false;
            }
        }
        return true;
    }
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isBipartite(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
