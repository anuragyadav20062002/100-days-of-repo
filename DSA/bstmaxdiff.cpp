//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};

Node *insert(Node *tree, int val) {
    Node *temp = NULL;
    if (tree == NULL) return new Node(val);

    if (val < tree->data) {
        tree->left = insert(tree->left, val);
    } else if (val > tree->data) {
        tree->right = insert(tree->right, val);
    }

    return tree;
}


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void fun(Node* r,int &t,int &ans){
        if(r==NULL)
            return;
        t+=(r->data);
        fun(r->left,t,ans);
        fun(r->right,t,ans);
        if(r->left==NULL && r->right==NULL) 
            ans=min(ans,t);
        t-=(r->data);
        return;
    }

    void f(Node* r,int target,int &sum,Node* &tar){
        if(tar)
            return;
        if(r==NULL)
            return;
        if(r->data==target){
            tar=r;
            // mila=1;
            return;
            
        }
        sum+=(r->data);
        if(tar)
            return;
        f(r->left,target,sum,tar);
        if(tar)
            return;
        f(r->right,target,sum,tar);
        if(tar)
            return;
        sum-=(r->data);
        return;
    }
    
    
    
    
    int maxDifferenceBST(Node *root,int target){
        int sum=0;
        Node* tar=NULL;
        f(root,target,sum,tar);
        if(!tar)
            return(-1);
        // cout<<sum<<endl;
        
        int ans=INT_MAX;
        int t=0;
        fun(tar->left,t,ans);
        t=0;
        fun(tar->right,t,ans);
        if(ans==INT_MAX)
            ans=0;
        return(sum-ans);
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        Node *root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            root = insert(root, k);
        }

        int target;
        cin >> target;
        Solution ob;
        cout << ob.maxDifferenceBST(root, target);
        cout << endl;
    }
}
// } Driver Code Ends