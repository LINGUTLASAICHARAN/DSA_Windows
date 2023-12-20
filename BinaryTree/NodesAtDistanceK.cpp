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

void PrintNodesInSubTree(Node *target, int k)
{
    if (target == NULL)
    {
        cout << "k = " << k << endl;
        return;
    }

    if (k == 0)
    {
        cout << target->val << endl;
        return;
    }

    PrintNodesInSubTree(target->left, k - 1);
    PrintNodesInSubTree(target->right, k - 1);
}

// the nodes can be the childern of the target node or they can be connected to the parent in the other part
void markParents(Node *root, map<Node *, Node *> &parent)
{
    parent[root] = NULL;
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {

        Node *temp = q.front();
        q.pop();

        if (temp->left)
        {
            q.push(temp->left);
            parent[temp->left] = temp;
        }
        if (temp->right)
        {
            q.push(temp->right);
            parent[temp->right] = temp;
        }
    }
}

void NodesAtDistanceK(Node *root, Node *target, int k)
{
    cout << "target is " << target->val << "  distance is "<< k <<  endl;
    map<Node *, Node *> parent;
    markParents(root, parent);
    // for(auto ele : parent){
    //     if(ele.second){
    //         cout << ele.first->val << " "<<ele.second->val << endl;
    //     }
    // }

    queue<Node *> q;
    q.push(target);

    set<Node *> visited;

    while (!q.empty())
    {
        if (k == 0)
            break;

        // cout << "k = " << k << endl;

        int s = q.size();
        for (int i = 0; i < s; i++)
        {
            Node *temp = q.front();
            q.pop();
            visited.insert(temp);
            // cout << "temp is " << temp->val << endl;
            if (temp->left && (visited.find(temp->left) == visited.end()))
            {
                // cout << "pushing" << temp->left->val << endl;
                q.push(temp->left);
            }

            if (temp->right && (visited.find(temp->right) == visited.end()))
            {
                // cout << "pushing" << temp->right->val << endl;
                q.push(temp->right);
            }

            if (parent[temp] && (visited.find(parent[temp]) == visited.end()))
            {
                // cout << "pushing" << parent[temp]->val << endl;
                q.push(parent[temp]);
            }
        }

        k--;
    }

    if (k == 0)
    {
        while (!q.empty())
        {
            cout << q.front()->val << endl;
            q.pop();
        }
    }
    else{
        cout << "None found"<<endl;
    }
}

int main()
{

    Node *root = makeTree();
    Node *target = root->right->right->right; 

    NodesAtDistanceK(root, target, 3); // nodes at distance 2 from node 2
    return 0;
}