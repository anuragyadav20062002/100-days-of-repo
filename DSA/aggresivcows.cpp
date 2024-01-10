//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution
{
public:

    int solve(int n, int k, vector<int> &ar) 
    {
        sort(ar.begin(),ar.end());
        long low=0,high=1000000000;
        int ans = 0;
        while(low<=high)
        {
            long mid = (low+high)/2;
            int count=1,left=0;
            for(int i=1;i<n;i++)
            {
                if(ar[i]-ar[left]>=mid)
                {
                    count++;
                    left = i;
                }
            }
            if(count>=k)
            {
                // cout<<low<<" "<<high<<endl;
                ans = mid;
                low = mid+1;

            }
            else
            {
                   high = mid-1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends