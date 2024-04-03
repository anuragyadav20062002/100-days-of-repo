//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution{
    public:
 int getIndex(int s,int e,int *inorder,int val){
        for(int i=s; i<=e; i++){
            if(inorder[i]==val){
                return i;
            }
        }
        return -1;
    }
    void buildTree(int &i,int s,int e,int *preorder,int *inorder,vector<int>&tree){
         if(s<=e){ 
                int idx=getIndex(s,e,inorder,preorder[i]);
                i++;
                if(idx==-1) return;
                buildTree(i,s,idx-1,preorder,inorder,tree);
                buildTree(i,idx+1,e,preorder,inorder,tree);
                tree.push_back(inorder[idx]);
         }        
    }
    bool checktree(int preorder[], int inorder[], int postorder[], int N) 
    { 
        vector<int>tree;
        int x=0;
        buildTree(x,0,N-1,preorder,inorder,tree);
        if(tree.size()<N) return false;
        for(int i=0; i<N; i++){
            if(tree[i]!=postorder[i]) return false;
        }
        return true;
    } 

};


//{ Driver Code Starts.

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int preorder[n];
		int inorder[n];
		int postorder[n];

		for (int i = 0; i < n; ++i)
			cin>>preorder[i];

		for (int i = 0; i < n; ++i)
			cin>>inorder[i];

		for (int i = 0; i < n; ++i)
			cin>>postorder[i];
        
        Solution obj;
		if(obj.checktree(preorder, inorder, postorder, n))
			cout << "Yes\n";
		else
			cout<<"No\n";
	} 
	return 0; 
} 


// } Driver Code Ends