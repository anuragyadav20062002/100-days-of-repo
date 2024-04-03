//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>

using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}



// } Driver Code Ends
// User function Template for C++

class Solution{
    
    public:
  struct E { int v,d; };
vector<E> L;
int D=0, c=0, i=0, l=0, r=100000;
void dfs(Node* n, int d) {
    D = max(D, d);
    if (!n) return;
    dfs(n->left, d+1);
    L.push_back({n->data,d});
    dfs(n->right, d+1);
}
pair<int, int> shortestRange(Node *root) {
    dfs(root, 0);
    vector<int> F(D);
    for (auto& e: L) {
        if (!(F[e.d]++)) c++;
        if (c==D) {
            if (e.v-L[i].v < r-l)
                l=L[i].v, r=e.v;
            while (c==D)
                if (!(--F[L[i++].d])) c--;
            if (e.v-L[i-1].v < r-l)
                l=L[i-1].v, r=e.v;
        }
    }
    return {l,r};
}
};

//{ Driver Code Starts.
int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        Solution obj;
        pair<int, int> range = obj.shortestRange(root);
        cout << range.first << " " << range.second << "\n";
    }

    return 0;
}
// } Driver Code Ends