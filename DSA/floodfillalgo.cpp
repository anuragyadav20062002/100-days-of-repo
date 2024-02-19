//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>&image, vector<vector<int>>&ans,
    int newColor, int delRow[], int delCol[], int initColor)
    {
        ans[row][col]=newColor;
        int n = image.size();
        int m = image[0].size();
        
        for(int i = 0; i < 4; i++)
        {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol] == initColor
            && ans[nrow][ncol] != newColor)
            {
                dfs(nrow,ncol,image,ans,newColor,delRow,delCol,initColor);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor)
    {
        vector<vector<int>>ans = image;
        int initColor = image[sr][sc];
        int delRow[4] = {-1,0,+1,0};
        int delCol[4] = {0,+1,0,-1};
        
        dfs(sr,sc,image,ans,newColor,delRow,delCol,initColor);
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends