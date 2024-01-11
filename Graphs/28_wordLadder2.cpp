#include <bits/stdc++.h>
using namespace std;

// gfg link  https://bit.ly/3As1nQw
// TUF link : https://takeuforward.org/graph/g-30-word-ladder-ii/

class Solution
{
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string> &wordList)
    {

        set<string> st(wordList.begin(), wordList.end());
        queue<vector<string>> q;
        vector<vector<string>> ans;
        vector<string> visAtLevel;
        q.push({beginWord});
        st.erase(beginWord);
        int level = 0;
        while (!q.empty())
        {
            auto vec = q.front();
            q.pop();

            if(vec.size() > level){
                level++;
                for(auto it : visAtLevel) st.erase(it);
                visAtLevel.clear();
            }


            string s = vec.back();
            if(s == endWord) {
                if(ans.size() == 0){
                    ans.push_back(vec);
                }
                else if(vec.size() == ans[0].size()) {
                    ans.push_back(vec);
                }
            }

            for (int j = 0; j < s.size(); j++)
            {
                for (char c = 'a'; c <= 'z'; c++)
                {
                    string n = s;
                    n[j] = c;
                    if (st.find(n) != st.end())
                    {
                        vec.push_back(n);
                        visAtLevel.push_back(n);
                        q.push(vec);
                        vec.pop_back();
                    }
                }
            }
        }
        return ans;
    }
};

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for (string i : a)
        x += i;
    for (string i : b)
        y += i;

    return x < y;
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<string> wordList(n);
        for (int i = 0; i < n; i++)
            cin >> wordList[i];
        string startWord, targetWord;
        cin >> startWord >> targetWord;
        Solution obj;
        vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
        if (ans.size() == 0)
            cout << -1 << endl;
        else
        {
            sort(ans.begin(), ans.end(), comp);
            for (int i = 0; i < ans.size(); i++)
            {
                for (int j = 0; j < ans[i].size(); j++)
                {
                    cout << ans[i][j] << " ";
                }
                cout << endl;
            }
        }
    }
    return 0;
}
