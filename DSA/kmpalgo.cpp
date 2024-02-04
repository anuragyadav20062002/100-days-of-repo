//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
            //code hee.
                        int n = txt.length();
            int m = pat.length();
            vector<int> res;
            
            //#windows = n-m+1
            for(int i=0; i<n-m+1; i++){
                //
                string curr = txt.substr(i, m);
                if(curr == pat) res.push_back(i+1); // bcz of '1' based indexing
            }
            //
            return res;

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
        if(res.size()==0)
            cout<<"-1 ";
        else
            for (int i : res)
                cout << i << " ";
        cout << endl;
    }
    return 0;
}


// } Driver Code Ends