//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

int countDistinctSubstring(string s);

int main()
{
 int t,l,i,j;
 int temp;
    cin>>t;
 while(t--){
 string s;
  cin>>s;
  cout<<countDistinctSubstring(s)<<endl;

 }
}


// } Driver Code Ends


/*You are required to complete this method */
struct Node{
    Node* links[26];

    bool containsKey(char ch){
        return links[ch - 'a'];
    }
    void put(char ch, Node* node){
        links[ch - 'a'] = node;
    }
    Node* get(char ch){
        return links[ch - 'a'];
    }
};
class Trie{
public:
    Node* root;
    Trie(){
        root = new Node();
    }
    int insert(string word){
        int n = word.size();
        int ans = 0;
        Node* node = root;
        for(int i = 0; i < n; i++){
            if(node -> containsKey(word[i]) == false){
                node -> put(word[i], new Node());
                ans++;
            }
            node = node -> get(word[i]);
        }
        return ans;
    }
};

int countDistinctSubstring(string s)
{
    int n = s.length();
    int ans = 0;
    Trie* trie = new Trie();
    for(int i = 0; i < n; i++){
       ans +=  trie -> insert(s.substr(i, n - i + 1));
    }
    return ans + 1;
}