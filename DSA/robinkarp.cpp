//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
            //code here.
            vector<int> v;
        int count = 0;
        int j = pat.length();
        
        for (int i = 0; i <= txt.length() - j; i++) {
            string temp = txt.substr(i, j); // Extract a substring of length j starting at position i in txt
            if (temp == pat) {
                v.push_back(i+1);
                count++;
            }
        }
        
        if (count > 0) {
            return v;
        } 
        else {
            v.push_back(-1);
            return v;
        }
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends