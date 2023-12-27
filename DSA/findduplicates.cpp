//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    vector<int> duplicates(long long arr[], int n) {
        // code here
      unordered_map<int,int>p;
        vector<int>x;
        for(int i=0;i<n;i++)
        {
            p[arr[i]]++;
        }
        for(auto i:p)
        {
            if(i.second>1)
            {
                x.push_back(i.first);
            }
        }
        if(x.empty())
        {
        x.push_back(-1);
        return x;
        }
        else
        {
            sort(x.begin(),x.end());
        return x;
        }
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        long long a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends