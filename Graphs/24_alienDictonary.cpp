#include <bits/stdc++.h>
using namespace std;

//  https://bit.ly/3C9N6ZU
class Solution{
    private: 
    vector<int> topoSort(vector<int> adj[], int V) {
        vector<int> ans, inDegree(V,0);
        queue<int>q;

        for (int i = 0; i < V; i++)
        {
            for(auto node : adj[i]) {
                inDegree[node]++;
            }
        }
        
        for (int i = 0; i < V; i++)
        {
            if(inDegree[i] == 0) q.push(i);
        }

        while (!q.empty())
        {
            int x = q.front();
            ans.push_back(x);
            q.pop();
            for(int node : adj[x]){
                inDegree[node]--;
                if(inDegree[node]== 0) q.push(node);
            }
        }
        
        return ans;
        

    }
    public:
    string findOrder(string dict[], int N, int K) {
        vector<int> adj[K]; // K characters so K nodes

        for (int i = 0; i < N-1; i++)
        {
            string s1 = dict[i], s2 = dict[i+1]; // comparing dict[i] with dict[i+1]
            int minlen = min(s1.size(), s2.size()); // need to compare the characters in the common length only

            for (int i = 0; i < minlen; i++)
            {
                // if two characters are equal no decision can be made
                if(s1[i] != s2[i]){
                    // s1[i] --> s2[i]
                    adj[s1[i]-'a'].push_back(s2[i]-'a'); // subtract with 'a' assuming that only lower case alphabets are used
                    break;
                }
            }
        }

        vector<int> ans = topoSort(adj, K);
        string answer ="";

        for (int i = 0; i < ans.size(); i++)
        {
            answer += char(ans[i]+'a');
        }
        

        return answer;
    }
};


string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}
