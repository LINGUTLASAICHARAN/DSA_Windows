#include <bits/stdc++.h>
using namespace std;

struct Node
{

    Node *left;
    Node *right;
    int val;

    Node(int x)
    {
        val = x;
        left = right = NULL;
    }
};

Node *makeTree()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->left->left = new Node(40);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->right->right = new Node(8);
    return root;
    /*
              1
             / \
            2   3
           / \ / \
          4  5 6  7
         /         \
        40          8
     */
}


// For each node, compute:

// 1. Node val

// 2. Max path through left child + node val

// 3. Max path through right child + node val

// 4. Max path through left child + Max path through right child + node val

// 5. Path is the sequence of edges like in a graph 

int maxPathSumUtil(Node * root , int &a){
    if(!root) return 0;

    int l = maxPathSumUtil(root->left,a );
    int r = maxPathSumUtil(root->right , a);
    int v = root->val;

    int nodeMax = max(max(v,v+l+r),max(v+ l,v+ r));

    a = max(nodeMax , a);
    return max(v ,max(v+l , v+r ));    
}

int maxPathSum(Node * root){
    int ans  = INT_MIN;

    maxPathSumUtil(root , ans);
    return ans;


}

int main(){
    
    Node * root = makeTree();

    cout << "Max path sum = " << maxPathSum( root);
    return 0;
}