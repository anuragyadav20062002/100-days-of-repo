//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    int n;
    int m;
    int arr[4]={-1,1,0,0};
    int brr[4]={0,0,1,-1};
    
    int dfs(int i,int j,vector<vector<int>>&matrix)
    {   if(i>=n || i<0 ||j>=m || j<0)
         {
        return 0;
        }
        if(matrix[i][j]==0)
        {
            return 1;
        }
        matrix[i][j]=0;
        int ans=1;
        for(int k=0;k<4;k++)
        {
           ans=ans&dfs(i+arr[k],j+brr[k],matrix); 
        }
        return ans;
    }
    int closedIslands(vector<vector<int>>& matrix, int N, int M) {
        // Code here
        n=N;
        m=M;
        int count=0;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                if(matrix[i][j])
                {
                    if(dfs(i,j,matrix))
                    {
                        ++count;
                    }
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends