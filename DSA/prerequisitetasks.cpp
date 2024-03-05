//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    bool isPossible(int N,int P, vector<pair<int, int> >& prerequisites) {
      vector<int>adj[N];
        for(auto itr:prerequisites )
        {
            adj[itr.first].push_back(itr.second);
        }
        
        int indegree[N] {0};
        for(int i=0;i<N;i++)
        {
            for(auto itr:adj[i]){
                indegree[itr]++;
            }
        }
        
        queue<int>q;
        for(int i=0;i<N;i++)
        {
            if(indegree[i] == 0)
            q.push(i);
        }
        
        
        vector<int>topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            
            
            for(auto itr : adj[node])
            {
                indegree[itr]--;
                if(indegree[itr] == 0)
                q.push(itr);
            }
        }
        
        
        if(topo.size() == N)return true;
        
        else 
        return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N,P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends