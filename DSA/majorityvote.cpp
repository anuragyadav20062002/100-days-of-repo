//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> Solve(int n, vector<int>& nums) {
        // Code here
        int c1=0,c2=0;
        int e1= INT_MIN;
        int e2=INT_MIN;
        
        for(int i=0;i<n;i++){
            if(c1==0 && e2!=nums[i]){
                c1++;
                e1=nums[i];
            }
            else if(c2==0 && e1!=nums[i]){
                c2++;
                e2=nums[i];
            }
            else if(nums[i]==e1) c1++;
            else if(nums[i]==e2) c2++;
            else{
                c1--;
                c2--;
            }
        }
        
        vector<int> ans;
        
        c1=0,c2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==e1) c1++;
            if(nums[i]==e2) c2++;
        }
        int mini = int(n / 3) + 1;
        if(c1>=mini) ans.push_back(e1);
        if(c2>=mini) ans.push_back(e2);
        
        if(ans.size()==0){
         ans.push_back(-1);
        }

        
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        Solution obj;

        vector<int> res = obj.Solve(n, a);

        for (auto x : res) cout << x << " ";

        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends