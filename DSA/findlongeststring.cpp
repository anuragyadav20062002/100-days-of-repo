//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
string longestString(vector<string> &arr)
    {
        sort(arr.begin(), arr.end());
        unordered_map<string, bool> map;
        
        for(int i=0; i<arr.size(); i++){
            
            if(arr[i].size() == 1)
                map[arr[i]] = true;
            
            else {
                string temp = arr[i];
                temp.pop_back();
                
                if(map[temp] == true)
                    map[arr[i]] = true;
                else 
                    map[arr[i]] = false;
            }
        }
        string ans = "";
        for(int i=0; i<arr.size(); i++){
            if(map[arr[i]] == true && arr[i].size() > ans.size())
                ans = arr[i];
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution obj;
        string w = obj.longestString(v);
        cout << w << "\n";
    }
    return 0;
}

// } Driver Code Ends