#include <bits/stdc++.h>
using namespace std;

// https://bit.ly/3dJdQXE
class Solution {
    private : 

    void topoSort(vector<pair<int,int>> adj[],  vector<int> &isVisited, stack<int> &s, int node){

            isVisited[node] = 1;
            for(auto p : adj[node]) {
                int adjNode = p.first;
                if(!isVisited[adjNode]) {
                    topoSort(adj,isVisited,s,adjNode);
                }
            }
            s.push(node);
    }
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges) {
       
       vector<pair<int,int>> adj[N];
       for (int i = 0; i < M; i++)
       {
        int u = edges[i][0], v = edges[i][1], wt = edges[i][2];
        adj[u].push_back({v,wt});
       }
       
       stack<int> s; 
       vector<int> isVisited(N,0);
       for (int i = 0; i < N; i++){
        if(!isVisited[i]) {
            topoSort(adj, isVisited, s ,i);
        }
       }

       vector<int> dist(N,1e9);
       dist[0] = 0;
       
       while (!s.empty())
       {
            int node = s.top();
            s.pop();

            for(auto edge : adj[node]){
                int adjNode = edge.first;
                int edgeWeight = edge.second;
                if(dist[adjNode] > dist[node] + edgeWeight) {
                    dist[adjNode] = dist[node] + edgeWeight;
                }
            }
       }
       
       
        for (int i = 0; i < N; i++)
       {
        if(dist[i] == 1e9) dist[i] = -1;
       }
       return dist; 
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}
