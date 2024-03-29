//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

//Back-end complete function Template for C++

class Solution{
    public:
unordered_map<string, bool> mp;
    bool isScramble(string s1, string s2){
        if (s1 == s2)
            return true; // screambled string
    
        string key = s1 + "*" + s2;
        if (mp.count(key) != 0)
            return mp[key];
    
        /* Pruning - checking frequency of characters in both string */
        int n = s1.size();
        vector<int> f1(26), f2(26);
        for (int i = 0; i < n; i++)
        {
            f1[s1[i] - 'a']++;
            f2[s2[i] - 'a']++;
        }
    
        if (f1 != f2)
            return mp[key] = false;
    
        /* Patitioning string into n - 1 partitions */
        for (int i = 1; i < n; i++)
        {
            if ((isScramble(s1.substr(0, i), s2.substr(0, i)) and isScramble(s1.substr(i), s2.substr(i))) or (isScramble(s1.substr(0, i), s2.substr(n - i)) and isScramble(s1.substr(i), s2.substr(0, n - i))))
                return mp[key] = true; /* (x == x' and y == y') or (x == p' and y == q') */
        }
    
        return mp[key] = false;
    }     
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        string S1, S2;
        cin>>S1>>S2;
        Solution ob;
        
        if (ob.isScramble(S1, S2)) {
            cout << "Yes";
        }
        else {
            cout << "No";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends