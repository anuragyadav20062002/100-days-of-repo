//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int unvisitedLeaves(int N, int leaves, int frogs[]) {
        // Code here
             // Code here
        int vis[l+1] = {0};
        int count = 0;
        
        for(int i = 0; i<n ; i++){
            
            if(frogs[i]==1) return 0;
            
            if(frogs[i]<=l && vis[frogs[i]]==0){
                 
                for(int j =frogs[i] ; j<=l ; j=j+frogs[i]){
                    if(vis[j]==0) count++;
                     vis[j] = 1;
                }
            }
        }
        
        return l-count;
    }
};


//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, leaves;
        cin >> N >> leaves;
        int frogs[N];
        for (int i = 0; i < N; i++) {
            cin >> frogs[i];
        }

        Solution ob;
        cout << ob.unvisitedLeaves(N, leaves, frogs) << endl;
    }
}
// } Driver Code Ends