//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/


class Solution
{
    public:
    //Function to rotate a linked list.
    Node* rotate(Node* head, int k)
    {
        // Your code here
                // Your code here
        int len=findlen(head);
        if(len==k){
            return head;
        }
        Node *p=head;
        int n=k;
        while(n!=0){
            p=p->next;
            n--;
        }
        Node *l=head;
        while(l->next!=p){
            l=l->next;
        }
        Node *q=p;
        while(q->next!=NULL){
            q=q->next;
        }
        q->next=head;
        l->next=NULL;
        head=p;
        return head;
    }
    int findlen(Node* head){
        int len=0;
        Node *p=head;
        while(p!=NULL){
            len++;
            p=p->next;
        }
        return len;
    }
};
    


//{ Driver Code Starts.

void printList(Node *n)
{
    while (n != NULL)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, val, k;
        cin>>n;
        
        cin>> val;
        Node *head = new Node(val);
        Node *tail = head;
        
        for(int i=0; i<n-1; i++)
        {
            cin>> val;
            tail->next = new Node(val);
            tail = tail->next;
        }
        
        cin>> k;
        
        Solution ob;
        head = ob.rotate(head,k);
        printList(head);
    }
    return 1;
}

// } Driver Code Ends