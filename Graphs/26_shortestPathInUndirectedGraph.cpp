#include <bits/stdc++.h>
using namespace std;

// https://bit.ly/3RGnHLH
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){

        vector<int> adj[N];
        // build the adjacency matrix
        for (int i = 0; i < M; i++)
        {
           int u = edges[i][0], v = edges[i][1];
           adj[u].push_back(v);
           adj[v].push_back(u);
        }
        // storing distances in an array
        vector<int> dist(N, 1e9);

        dist[src] = 0;
        queue<int>q;
        q.push(src);

        // do a bfs from src
        while (!q.empty())
        {
           int x = q.front();
           q.pop();

           for(int node : adj[x]){
                if(dist[node] > dist[x] + 1){
                    // if there is a shorter path update it and push the new node into queue
                    q.push(node);
                    dist[node] = dist[x] + 1;
                }
           }
        }
        // replacing the 1e9 with -1
        for(auto & x : dist){
            if(x == 1e9) x = -1;
        }
        
        return dist;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}
