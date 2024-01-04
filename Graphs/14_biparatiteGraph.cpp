
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
        isColored[i] = 1; // coloring it 1
        q.push(i);

        while (q.size() != 0)
        {
            int head = q.front();
            q.pop();

            for (int j = 0; j < adj[head].size(); j++)
            {
                if (!isColored[adj[head][j]])
                {
                    // if an adjacent node is not colored color the opposite of heads color and push it to queue
                    q.push(adj[head][j]);
                    if (isColored[head] == 1)
                    {
                        isColored[adj[head][j]] = 2;
                    }
                    else
                    {
                        isColored[adj[head][j]] = 1;
                    }
                }
                else if (isColored[head] == isColored[adj[head][j]])
                    return false;
            }
        }

        return true;
    }

public:
    bool isBipartite(int V, vector<int> adj[])
    {
        vector<int> isColored(V, 0);

        for (int i = 0; i < V; i++)
        {
            bool ans;
            if (!isColored[i])
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
