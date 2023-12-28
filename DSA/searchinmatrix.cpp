//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	


	int matSearch (vector <vector <int>> &mat, int N, int M, int X)
	{
	    // your code here
	    int rowIndex = 0, colIndex = M-1;
	    while(rowIndex < N && colIndex >= 0){
	        int element = mat[rowIndex][colIndex];
	        if(element == X)
	        return 1;
	        if(X<element){
	            colIndex--;
	        }
	        if(X>element){
	            rowIndex++;
	        }
	    }
	    return 0;
	}
};

//{ Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--){
        int n, m; cin >> n >> m;
        vector <vector <int>> arr (n, vector <int> (m));
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
                cin >> arr[i][j];
                
        int x; cin >> x;
        Solution ob;
        cout << ob.matSearch (arr, n, m, x) << endl;
    }
}
// } Driver Code Ends