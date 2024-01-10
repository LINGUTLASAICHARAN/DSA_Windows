#include <bits/stdc++.h>
using namespace std;

//https://bit.ly/3PvBfsm
class Solution
{

	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
        vector<int> inDegree(V,0); // maintain the inDegree of all the nodes

        for (int i = 0; i < V; i++)
        {
            for(int node : adj[i]) {
                inDegree[node]++;  // if there is an edge to node the in crease the indegree of that node
            }
        }
        
        queue<int> q;
        vector<int> ans;

        for (int i = 0; i < V; i++)
        {
            if(inDegree[i] == 0){
                q.push(i);  // add the nodes with 0 indegree to be removed from graph
            }
        }
        
        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            ans.push_back(x); // add the removed nodes from the queue to the ans

            for(int node : adj[x]){
                // if is an edge from x to node the upon removal of x the in degree of node will reduce by 1
                inDegree[node]--;
                if(inDegree[node] == 0) q.push(node); // if indegree becomes 0 the it can be removed. so, push into the queue
            }
        }
        
        return ans;
	}
};

int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
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
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
