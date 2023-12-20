#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main(){
    int n , m;
    cin >> n >> m;

    int adjMatrix[n+1][n+1]; // stores the graph in O(n2) space

    // for (int i = 0; i < m; i++)
    // {
    //     int x , y;
    //     cin >> x >>y;
    //     adjMatrix[x][y] = adjMatrix[y][x] = 1;
    // }
    
    // storing in adjacency list

    vector< vector<int> > adjList(n+1); // stores in O(2m) space

    for (int i = 0; i < m; i++)
    {
        int x , y;
        cin >> x >>y;
        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }
    
    
    return 0;
}