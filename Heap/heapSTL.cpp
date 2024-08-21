#include <bits/stdc++.h>
using namespace std;

int main()
{
    // max heap by default
    priority_queue<int> maxHeap;

    cout << "max heap" <<endl;
    maxHeap.push(5);
    maxHeap.push(3);
    maxHeap.push(4);
    maxHeap.push(2);
    maxHeap.push(20);
    cout << maxHeap.size() <<endl;
    cout << maxHeap.top() << endl;
    maxHeap.pop();
    cout << maxHeap.top() << endl;

    priority_queue<int, vector<int>, greater<int>> minHeap;

    cout << "min heap"<< endl;
    minHeap.push(5);
    minHeap.push(3);
    minHeap.push(4);
    minHeap.push(2);
    minHeap.push(20);
    cout << minHeap.size() <<endl;
    cout << minHeap.top() << endl;
    minHeap.pop();
    cout << minHeap.top() << endl;
    return 0;
}