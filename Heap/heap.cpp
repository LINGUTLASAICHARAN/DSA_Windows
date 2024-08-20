#include <bits/stdc++.h>

using namespace std;

class MaxHeap
{
    // array based implementation
    public:
    vector<int> v{0}; // just put 0 in first position

    // insertion takes O(log(n))
    void insert(int val) {
        v.push_back(val);
        int pos = v.size() - 1; // position is size - 1  

        // keep running the loop as long as position is not 1 and parent is smaller than child
        while (pos > 1 && v[pos/2] < v[pos])
        {
           swap(v[pos/2], v[pos]);
           pos = pos/2;
        }
        
    }

    void print() {

        for(int i = 1 ; i < v.size(); i++){
            cout<< v[i] <<" ";
        }
        cout<<endl;
    }

    void deleteFromHeap() {
        if(v.size() == 1) {
            cout << "nothing to delete";
            return;
        }

        v[1] = v[v.size() - 1]; // move last element to root element
        v.pop_back();

        // take root to correct position
        int size = v.size() - 1;

        int i = 1;

        
        while (i < size)
        {
           int left = 2 * i;
           int right = 2 * i + 1;

           if(left <= size && v[i] < v[left] ) {
            swap(v[i] , v[left]);
            i = left;
           } else if(right <= size && v[i] < v[right]) {
            swap(v[i], v[right]);
             i = right;
           } else {
            return;
           }
        }
        

    }
};

int main()
{

    MaxHeap maxheap = MaxHeap();
    maxheap.insert(50);
    maxheap.insert(55);
    maxheap.insert(53);
    maxheap.insert(52);
    maxheap.insert(54);
    maxheap.deleteFromHeap();
    maxheap.print();
    return 0;
}