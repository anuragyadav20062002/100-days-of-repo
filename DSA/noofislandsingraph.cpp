//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
void mark(vector<vector<char>>& grid, int x, int y, int row, int col)
    {
        if(x<0 || y<0 || x>=row || y>=col || grid[x][y]!='1')
        return;
        
        grid[x][y]='2';
        
        mark(grid, x+1,y, row, col);
        mark(grid, x, y+1, row, col);
        mark(grid, x-1,y, row, col);
        mark(grid, x, y-1, row, col);
         mark(grid, x+1, y+1, row, col);
          mark(grid, x-1, y+1, row, col);
           mark(grid, x-1, y-1, row, col);
            mark(grid, x+1, y-1, row, col);
        
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size();
        if(n==0)
         return 0;
         int m=grid[0].size();
         
         int no_of_lnd=0;
         
         for(int i=0;i<n;i++)
         {
             for(int j=0;j<m;j++){   // DFS
                 if(grid[i][j]=='1')
                 {
                     mark(grid,i,j,n,m);
                     no_of_lnd++;
                 }
             }
         }
         
         return no_of_lnd;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends
