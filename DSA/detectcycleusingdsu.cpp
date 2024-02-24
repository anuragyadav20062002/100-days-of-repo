//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
   public:
    //Function to detect cycle using DSU in an undirected graph.
	 int parent[10001];
	 int find_parent(int x) {
	     if(parent[x]==x) return x;
	     return parent[x] = find_parent(parent[x]);
	 }
	 void Union(int a, int b) {
	     a = find_parent(a);
	     b = find_parent(b);
	     parent[b] = a;
	 }
	 void make_node(int a) {
	     parent[a] = a;
	 }
	int detectCycle(int V, vector<int>adj[])
	{
	    // Code here
	    for(int i=0;i<V;i++) make_node(i);
	    
	    for(int i = 0;i<V;i++) {
	        for(auto child:adj[i]) {
	            if(child>i && find_parent(i) == find_parent(child)) return true;
	            Union(i,child);
	        }
	    }
	    return false;
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		int ans = obj.detectCycle(V, adj);
		cout << ans <<"\n";	}
	return 0;
}
// } Driver Code Ends