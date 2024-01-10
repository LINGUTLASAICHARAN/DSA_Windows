//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

//https://bit.ly/3SYjQvp

class Solution
{
  public:
    vector<int> findOrder(int N, int P, vector<vector<int>> prerequisites) 
    {
        vector<int> inDegre(N,0);
        vector<vector<int>> adj(N);
        for (int i = 0; i < P; i++)
        {
            inDegre[prerequisites[i][0]]++;
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        queue<int> q;
        vector<int> ans;
        for (int i = 0; i < N; i++)
        {
            if(inDegre[i] == 0) q.push(i);
        }
        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            ans.push_back(x);
            for(int node : adj[x]) {
                inDegre[node]--;
                if(inDegre[node] == 0) q.push(node);
            }
        }
        
        if(ans.size() == N) return ans;

        return{}; // this is how you return an empty vector or array
        
    }
};

//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends