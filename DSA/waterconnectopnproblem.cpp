//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    pair<int,int> solve(int node,vector<pair<int,int>> adj[],int di){
        
        for(auto it:adj[node]){
            di=min(di,it.second);
            return solve(it.first,adj,di);
        } 
        
        return {node,di};
        
    }
    vector<vector<int>> solve(int n,int p,vector<int> a,vector<int> b,vector<int> d)
    {
        // code here
        vector<pair<int,int>> adj[n+1];
        vector<int> indegree(n+1,0);
         vector<int> outdegree(n+1,0);
        for(int i=0;i<p;i++){
            adj[a[i]].push_back({b[i],d[i]});
            indegree[b[i]]++;
            outdegree[a[i]]++;
        }
        vector<vector<int>> ans;
        for(int i=1;i<=n;i++){

            if(indegree[i]==0 && outdegree[i]>0){
                int end=solve(i,adj,INT_MAX).first;
                int diameter=solve(i,adj,INT_MAX).second;
                ans.push_back({i,end,diameter});
            }
            
        }
        return ans;
        
        
        
    }
};

//{ Driver Code Starts.
int main()
{
	int t,n,p;
	cin>>t;
	while(t--)
    {
        cin>>n>>p;
        vector<int> a(p),b(p),d(p);
        for(int i=0;i<p;i++){
            cin>>a[i]>>b[i]>>d[i];
        }
        Solution obj;
        vector<vector<int>> answer = obj.solve(n,p,a,b,d);
        cout<<answer.size()<<endl;
        for(auto i:answer)
        {
            cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
        }
        
    }
	return 0;
}
// } Driver Code Ends