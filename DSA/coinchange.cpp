//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
long long solve(int coins[], int ind, int sum, int n, vector<vector<long long>>& dp){
        if(sum == 0) return 1;
        if(ind == n or sum < 0){
            return 0;
        }
        if(dp[ind][sum] != -1) return dp[ind][sum];
        long long take = solve(coins,ind,sum-coins[ind],n,dp);
        long long notTake = solve(coins,ind+1,sum,n,dp);
        return dp[ind][sum] = take + notTake;
    }
    long long int count(int coins[], int N, int sum) {

        // code here.
        vector<vector<long long>> dp(N+1, vector<long long> (sum+1,-1));
        long long ans = solve(coins,0,sum,N,dp);
        return ans != 1e8 ? ans : -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends