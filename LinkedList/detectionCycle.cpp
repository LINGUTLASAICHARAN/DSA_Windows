#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node(int x)
    {
        val = x;
        next = NULL;
    }
};

// pass reference of head
void insertAthead(Node *&head, int x)
{
    // create a new node
    Node *n = new Node(x);
    // make the next of new node = head
    n->next = head;
    // point head to new node 
    head = n;
}

// pass reference of head
void insertAttTail(Node * &head, int x)
{
    Node *n = new Node(x);
    Node *temp = head;
    if (head == NULL)
    {
        // there are 0 elements in linked list
        head = n;
        return;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

// dont pass head by reference
void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->val << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
}


bool detectCycle(Node *head)
{ // floyyds algorithm
    Node *fast = head;
    Node *slow = head;
    while (!(fast == NULL || fast->next == NULL)) // break if fast becomes null or fast->next becomes null
    {
        // when !(x || y) is the condition then ix x or y is true the loop breaks
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow){
            cout<<"met at " << fast->val <<endl;
            return true;
        }
    }
    return false;
}

void makeCycle(Node *head, int k)
{

    Node *start;
    int x = 1;
    Node *temp = head;
    // take temp to end
    while (temp->next != NULL)
    {
        // store a pointer to start of cycle which is at position k
        if (x == k)
            start = temp;

        temp = temp->next; 
        x++;
    }

    temp->next = start; // make the end point to 
}
void removeCycle(Node * &head){ // assuming cycle is there
    Node * slow = head, *fast = head;
    do{
        slow = slow->next;
        fast = fast->next->next;
    }while(fast != slow);

    // now take any pointer to head, fast here
    fast = head;
    while(fast->next != slow->next){ // move both pointers till they point to the same node
        fast = fast->next;
        slow = slow->next; 
    }
    // now the pointer that has not been moved is at the end of LL and just point it to null
    slow->next = NULL;
}




// datection and removal of loop is done here


int main()
{
    Node *head = NULL; // head node pointer

    for (int i = 1; i <= 6; i++)
    {
        insertAttTail(head, i);
    }
    print(head);
    makeCycle(head, 3);
    cout << "made cycle form end to 3"<<endl;
    cout << (detectCycle(head) ? "cyclefound" : "no cycle") << endl;
    removeCycle(head);
    cout << "cycle removed"<<endl;
    cout << (detectCycle(head) ? "cyclefound" : "no cycle found") << endl;
    print(head);
    return 0;
}
