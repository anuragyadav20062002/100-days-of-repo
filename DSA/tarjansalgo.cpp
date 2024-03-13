//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
class Solution
{
	public:
    //Function to return a list of lists of integers denoting the members 
    //of strongly connected components in the given graph.
    
    //1.finding topological order
    void dfsTopo(int src,stack<int>&s,unordered_map<int,bool>&visited,vector<int>adj[])
    {
        visited[src]=true;
        for(auto nbr:adj[src])
        {
            if(!visited[nbr])
            {
                dfsTopo(nbr,s,visited,adj);
            }
        }
        //return aate wqt push to stack'
        s.push(src);
    }
    //sab 2 wale
    void dfs2(int src,unordered_map<int,bool>&visited2,vector<int>NewAdj[],  vector<int>&res){
        visited2[src]=true;
        //**
        res.push_back(src);
        
        for(auto nbr:NewAdj[src])
        {
            if(!visited2[nbr])
            {
                dfs2(nbr,visited2,NewAdj,res);
            }
        }
        
    }
    
    vector<vector<int>> tarjans(int V, vector<int> adj[])
    {
       
        stack<int>s;
        unordered_map<int,bool>visited;
        // 1. find topo-order
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            dfsTopo(i,s,visited,adj);
            
        }
        // 2. reverse All edges
        //create new AdjList-->  V->U
        vector<int> NewAdj[V];
        for(int i=0;i<V;i++)
        {
            visited[i]=0;
            for(auto nbr:adj[i])
            {
              NewAdj[nbr].push_back(i) ; 
            }
        }
        
        // 3. traverse using DFS
        
        unordered_map<int,bool>visited2;
         vector<vector<int>>ans;
         vector<int>res;
         while(!s.empty())
         {
             int node=s.top();
             s.pop();
             if(!visited2[node])
             {
                
                 dfs2(node,visited2,NewAdj,res);
                 sort(res.begin(),res.end());
                  ans.push_back(res);
                  
             }
             res.clear();
         }
        sort(ans.begin(),ans.end());
        return ans;
        
    }    
   };

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for(int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<vector<int>> ptr = obj.tarjans(V, adj);

        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                if(j==ptr[i].size()-1)
                    cout<<ptr[i][j];
                else
                    cout<<ptr[i][j]<<" ";
            }
            cout<<',';
        }
        cout<<endl;
    }

    return 0;
}


// } Driver Code Ends