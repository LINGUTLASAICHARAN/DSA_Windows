#include<bits/stdc++.h>

using namespace std;

int main() {

    set<int> s = {1,2,4,4};
    vector<int> vec = {44,566,7,7,88,76,54,4,4,34}; // duplicates are removed automatically

    set<int> st(vec.begin(), vec.end());

    for(auto it : s){
        cout << it << endl;
    }
    cout << "second vector" <<endl;

    for(auto it : st) cout << it << endl;
}