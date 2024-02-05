//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b){
        if(a.length()!=b.length()){
            return false;
        }
        map<char,int>m1;
        for(int i = 0;i<a.length();i++){
            m1[a[i]]++;
        }
        for(int i =0;i<b.length();i++){
           if(m1[b[i]]==0){
               m1[b[i]]++;
           }
           else{
               m1[b[i]]--;
           }
        }
        
        for(auto it: m1){
           
           if(it.second!=0){
               return false;
           }
        }
        
        return true;
    }

};

//{ Driver Code Starts.

int main() {
    
    int t;

    cin >> t;

    while(t--){
        string c, d;

        cin >> c >> d;
        Solution obj;
        if(obj.isAnagram(c, d)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}

// } Driver Code Ends