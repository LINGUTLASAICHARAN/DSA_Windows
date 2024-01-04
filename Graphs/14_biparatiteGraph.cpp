
#include <bits/stdc++.h>
using namespace std;
// https://bit.ly/3SQQgId

class Solution
{
private:
    bool color(int i, vector<int> &isColored, vector<int> adj[])
    {
        // doing BFS
        queue<int> q;
        isColored[i] = 0; // coloring it 0
        q.push(i);

        while (q.size() != 0)
        {
            int head = q.front();
            q.pop();

            for (auto adjNode : adj[head])
            {
                if (isColored[adjNode] == -1)
                {
                    // if an adjacent node is not colored color the opposite of head's color and push it to queue
                    q.push(adjNode);
                    isColored[adjNode] = !isColored[head];
                }
                else if (isColored[head] == isColored[adjNode])
                    return false;
            }
        }

        return true;
    }

public:
    bool isBipartite(int V, vector<int> adj[])
    {
        // when a graph is not biparatite then it surely has a cycle with odd number of nodes in it 
        vector<int> isColored(V, -1);

        for (int i = 0; i < V; i++)
        {
            bool ans;
            if (isColored[i] == -1)
            {
                ans = color(i, isColored, adj);
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
