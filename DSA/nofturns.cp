//User function template for C++
/*
Structure of the node of the tree is as follows 
struct Node {
    struct Node* left, *right;
    int data;
};
*/

class Solution{
  public:
   int  findturn(struct Node *lcs,int first,int second,int prev,int t)
  {
     
      if(!lcs)
      {
          return  0;
      }
      if(lcs->data==first || lcs->data==second)
      {
         return  t;
      }
      int ans=0;
      if(prev==0)
      {
        ans=  findturn(lcs->left,first,second,0,t)+
            findturn(lcs->right,first,second,1,t+1);
           return ans;
      }
      else if(prev==1)
      {
        ans= findturn(lcs->left,first,second,0,t+1)+
          findturn(lcs->right,first,second,1,t);
          return ans;
      }
     
          ans=findturn(lcs->left,first,second,0,t)+
          findturn(lcs->right,first,second,1,t);
          return ans;
      
    }
  Node * findlcs(struct Node * root,int first,int second)
  {
      if(!root || root->data==first || root->data==second)
      {
          return root;
      }
      Node * left=findlcs(root->left,first,second);
      Node * right=findlcs(root->right,first,second);
      if(left && right)
      {
          return root;
      }
      if(!left)
      {
          return right;
      }
      if(!right)
      {
          return left;
      }
     
  }
    // function should return the number of turns required to go from first node to second node 
    int NumberOFTurns(struct Node* root, int first, int second)
    {
      // Your code goes here
      Node *lcs=findlcs(root,first,second);
      if(lcs->data==first || lcs->data==second)
      {
          return findturn(lcs->left,first,second,0,0)+findturn(lcs->right,first,second,1,0);
      }
      return 1+findturn(lcs->left,first,second,0,0)+findturn(lcs->right,first,second,1,0);
      
    }
};