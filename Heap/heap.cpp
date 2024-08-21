#include <bits/stdc++.h>

using namespace std;

/*
heap by love babbar
https://youtu.be/NKJnHewiGdc?si=_tev4daP8LPISpqT
*/


// log(n)
void heapify(vector<int> &v, int size, int curr)
{
    int largest = curr; // assume current node is the largest one

    // left is 2 * i and right is 2 * i + 1 in 1 based indexing and left is 2 * i + 1 , right is 2 * i + 2 in  0 based indexing
    int left = 2 * curr, right = 2 * curr + 1;

    // compare left and right with largest to find out the real largest one
    if (left <= size && v[left] > v[largest])
    {
        largest = left;
    }
    if (right <= size && v[right] > v[largest])
    {
        largest = right;
    }

    if (curr != largest)
    {
        swap(v[curr], v[largest]);
        heapify(v, size, largest);
    }
}

void heapSort(vector<int> &v, int size) {

    while (size > 1)
    {
        swap(v[1], v[size]);
        size--;

        // call heapify on root
        heapify(v,size,1);
    }
    
}

class MaxHeap
{
    // array based implementation
public:
    vector<int> v{0}; // just put 0 in first position

    // insertion takes O(log(n))
    void insert(int val)
    {
        v.push_back(val);
        int pos = v.size() - 1; // position is size - 1

        // keep running the loop as long as position is > 1 and parent is smaller than child

        while (pos > 1)
        {
            int parent = pos / 2;
            if (v[parent] < v[pos])
            {
                swap(v[parent], v[pos]);
                pos = parent;
            } 
            return;
        }
    }

    void print()
    {

        for (int i = 1; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;
    }

    void deleteFromHeap()
    {
        if (v.size() == 1)
        {
            cout << "nothing to delete";
            return;
        }

        v[1] = v[v.size() - 1]; // move last element to root element
        v.pop_back();

        // take root to correct position by using heapify algo
        int size = v.size() - 1;

        heapify(v, size, 1);
    }
};
int main()
{

    MaxHeap maxheap = MaxHeap();
    maxheap.insert(5);
    maxheap.insert(3);
    maxheap.insert(4);
    maxheap.insert(2);
    maxheap.deleteFromHeap();
    maxheap.print();

    vector<int> v{-1, 54, 53, 55, 52, 50,-10};
    int size = 6;

    // building heap from this array using heapify algorithm

    /*  leaf nodes are from n/2 to n in 1 based indexing    and   n/2 to n-1 in 0 based indexing
        so you only have to process the nodes forn n/2 - 1 to 1 in based indexing and n/2-1 to 0 in 0 based indexing
    */

    for (int i = size / 2 - 1; i > 0; i--)
    {
        heapify(v, size, i);
    }

    for (int i = 1; i <= size; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    heapSort(v,size);

    for(auto ele  : v) {
        cout << ele << " ";
    }
    cout <<endl;
    
    return 0;
}