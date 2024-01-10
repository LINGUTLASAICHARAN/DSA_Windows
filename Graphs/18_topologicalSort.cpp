#include <bits/stdc++.h>
using namespace std;
// https://bit.ly/3PvBfsm
class Solution{
    private : 
    void dfs(int i, vector<int> adj [], vector<int> &isVisited, stack<int> & ans) {

            isVisited[i] = 1;

            for(int adjNode : adj[i]) {
                if(!isVisited[adjNode]) dfs(adjNode, adj, isVisited, ans);
            }
            // after dfs is complete on i push it to stack
            // now all the nodes that have edges from i are below i in the stack
            ans.push(i);

    }

	public:
	// an ordering of nodes n1 n2 ... ni nj...... is topologically sorted if there is no edge from ni  to nj where i < j. simply put there should not be any forward edges
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
        vector<int> isVisited(V, 0), ans;
        stack<int> st;

	    for (int i = 0; i < V; i++)
        {
            if(!isVisited[i]) {
                // if not visited call dfs
                dfs(i,adj,isVisited,st);
            }
        }
        // collect the entries of stack top to bottom
        // here LIFO is helpful as the nodes that are reached last come at the start of vector as they are top of stack
        while(!st.empty()){
        
            ans.push_back(st.top()); // insert the top of stack into vector
            st.pop();
        }
        return ans;
        
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
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

        cout << endl <<"ans " <<check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends