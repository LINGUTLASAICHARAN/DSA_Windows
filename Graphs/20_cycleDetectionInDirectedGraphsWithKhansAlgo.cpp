#include <bits/stdc++.h>
using namespace std;
// https://bit.ly/3QwPVsi

class Solution
{
public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[])
    {

        vector<int> inDegree(V, 0);

        for (int i = 0; i < V; i++)
        {
            for (auto node : adj[i])
                inDegree[node]++;
        }
        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (inDegree[i] == 0)
                q.push(i);
        }
        int ans;
        while (!q.empty())
        {
            int x = q.front();
            ans++;
            q.pop();
            for (auto node : adj[x])
            {
                inDegree[node]--;
                if (inDegree[node] == 0)
                    q.push(node);
            }
        }
        return ans != V;
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends