#include<bits/stdc++.h>
using namespace std;

//https://bit.ly/3ApDfOm
class Solution {
public:
	bool isPossible(int N,int P, vector<pair<int, int> >& prerequisites) {
	    
        vector<int> inDegree(N,0);
        vector<vector<int>> adj(N);
        // implementing khans algorithm
        for (int i = 0; i < P; i++)
        {
            auto x = prerequisites[i];
            adj[x.second].push_back(x.first);
            inDegree[x.first]++;
        }
        queue<int> q;
        for (int i = 0; i < N; i++)
        {
            if(inDegree[i] == 0) q.push(i);
        }
        int count = 0;
        while (q.size() != 0)
        {
            int x= q.front();
            q.pop();
            count ++;
            for(int node : adj[x]) {
                inDegree[node]--;
                if(inDegree[node] == 0) q.push(node);
            }
        }
        
        return count == N;
        
        
	}
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }

        Solution ob;
        if (ob.isPossible(N,P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
