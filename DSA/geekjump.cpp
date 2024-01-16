//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
         // Code here
        if(n==1) return 0;
        int prev=abs(height[1]-height[0]);
        int prev2=0;
        for(int i=2; i<n; i++){
            int left=prev+abs(height[i]- height[i-1]);
            int right=prev2+abs(height[i]-height[i-2]);
            int ans=min(left, right);
            prev2=prev;
            prev=ans;
        }
        return prev;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends