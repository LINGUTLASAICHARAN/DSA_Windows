#include <bits/stdc++.h>
using namespace std;

class Solution
{

/*
    a node is eventual safe node if all the paths from it lead to a terminal node.
    so when we reverse the edges and start removing the terminal nodes i.e nodes with 0 indegree, the indegree of the eventual safe nodes will become 0 at some point in the removal process. This is because all the out going edges will lead to terminal nodes, now the terminal nodes are being removed and the out going edges became incoming egdes.

    So collect the nodes that get their indegree as 0 in the process. sort them and return as they are the eventual safe nodes.

    This is done using khans algorithm 
*/
public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[])
    {

        vector<int> inDegree(V, 0);
        vector<int> adjRev[V];
        for (int i = 0; i < V; i++)
        {
            // i --> node
            // reversing the edges
            for (auto node : adj[i])
            {
                // node --> i
                adjRev[node].push_back(i); // make sure to mark it in the new adjacencylist
                inDegree[i]++;
            }
        }

        queue<int> q;
        vector<int> ans;
        for (int i = 0; i < V; i++)
        {
            if (inDegree[i] == 0)
                q.push(i);
        }
        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            ans.push_back(x); // collecting the nodes with 0 indegree

            for (auto node : adjRev[x])
            {
                inDegree[node]--;
                if (inDegree[node] == 0)
                    q.push(node);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
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
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends