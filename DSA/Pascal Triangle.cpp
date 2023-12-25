//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// #define ll long long
class Solution{
public:
vector< long long > nthRowOfPascalTriangle( int n ) {
    vector< long long > v{ 1 };
    while ( --n ) {
        vector< long long > t( v.size()+1, 1 );
        for ( size_t i{ 1 }; i < v.size(); ++i )
            t[ i ] = ( v[ i ] + v[ i-1 ] ) % 1000000007;
        v = move( t );
    }
    return v;
}
};


//{ Driver Code Starts.


void printAns(vector<long long> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends