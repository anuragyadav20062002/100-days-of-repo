//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
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

class Solution{
  public:
    //Function to check whether the list is palindrome.
Node* getMid(Node* root) {
        
        Node* slow = root;
        Node* fast = root;
        
        while(fast->next != NULL and fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
    Node* reverse(Node* root) {
        
        if(root == NULL or root->next == NULL) {
            return root;
        }
        
        Node* smallHead = reverse(root->next);
        
        root->next->next = root;
        root->next = NULL;
        
        return smallHead;
    }

    bool isPalindrome(Node *head)
    {
        Node* mid = getMid(head);
        mid->next = reverse(mid->next);
        
        Node* curr1 = head;
        Node* curr2 = mid->next;
        
        while(curr2 != NULL) {
            if(curr1->data != curr2->data) {
                return false;
            }
            
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        
        return true;
    }
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends