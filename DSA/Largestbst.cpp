//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
vector<int> largestBSTBT(Node* root)

{

    // Base cases : When tree is empty or it has one child.

    if (root == NULL)

        return {INT_MAX, INT_MIN, 0};

 

    if (root->left == NULL && root->right == NULL)

 

        return {root->data, root->data, 1};

 

    // Recur for left subtree and right subtrees

    vector<int> left = largestBSTBT(root->left);

 

    vector<int> right = largestBSTBT(root->right);

 

    // Create a return variable and initialize its size.

    vector<int> ans(3, 0);

 

    // If whole tree rooted under current root is BST

    if ((left[1] < root->data) && (right[0] > root->data))

    {

        ans[0] = min(left[0], min(right[0], root->data));

 

        ans[1] = max(right[1], max(left[1], root->data));

 

        // Update answer for tree rooted under current 'root'

        ans[2] = 1 + left[2] + right[2];

        return ans;

    }

    // If whole tree is not BST, return maximum of left and right subtrees

    ans[0] = INT_MIN;

    ans[1] = INT_MAX;

    ans[2] = max(left[2], right[2]);

    return ans;

}

int largestBst(Node *root)

{

      return largestBSTBT(root)[2];

}
};

//{ Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.largestBst(root) << endl;
    }
    return 0;
}

// } Driver Code Ends