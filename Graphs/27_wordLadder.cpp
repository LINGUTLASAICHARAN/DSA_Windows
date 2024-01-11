#include <bits/stdc++.h>
using namespace std;

//  https://bit.ly/3PuJxk3
class Solution
{
public:
    int wordLadderLength(string startWord, string targetWord, vector<string> &wordList)
    {
        /*doing a bfs here using start node as startWord and changing one character at a time*/

        queue<pair<string, int>> q; // used to store strings with the distance

        set<string> s(wordList.begin(), wordList.end()); //  set to check if the new string is present int the list of allowed strings

        set<string> vis; // set maintaining visited strings

        q.push({startWord, 1}); 
        vis.insert(startWord);

        while (!q.empty())
        {
            string x = q.front().first;
            int d = q.front().second;

            q.pop();

            for (int i = 0; i < x.size(); i++) // loop targeting all positions in string
            {
                for (int c = 'a'; c <= 'z'; c++) // looping from a to z
                {
                    string n = x; // making a copy of string x to edit it
                    n[i] = char(c);  // replace the character at position i with char(c)


                    if (s.find(n) != s.end() && vis.find(n) == vis.end())
                    {
                        // if the new string n is in the set s and is not already visited 
                        q.push({n, d + 1});
                        vis.insert(n);
                        if (n == targetWord)
                            return d + 1;
                    }
                }
            }
        }

        return 0;
    }
};

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
        int ans = obj.wordLadderLength(startWord, targetWord, wordList);
        cout << ans << "\n";
    }
    return 0;
}