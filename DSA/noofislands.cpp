class DisjoinSet {
    public:
    vector<int> rank, parent, size;

    DisjoinSet(int n) {
        rank.resize(n+1,0);
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }
    
    int findUParent(int node) {
        if(parent[node] == node) return node;
        return parent[node] = findUParent(parent[node]);
    }
    
    bool isInSameComponent(int u, int v) {
        return (findUParent(u) == findUParent(v));
    }
    
    void unionByRank(int u, int v) {
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);
        
        if(ulp_v == ulp_u) return;
        
        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        } else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;  
        } else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    
    void unionBySize(int u, int v) {
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);
        
        if(ulp_v == ulp_u) return;
        
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
    
};

class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        vector<vector<int>> matrix(n,vector<int>(m, 0));
        vector<int> ans;
        DisjoinSet ds(n*m);
        int land = 0;
        
        int delrow[4] = {-1,0,1,0};
        int delcol[4] = {0,-1,0,1};
        for(auto it : operators) {
            int row = it[0];
            int col = it[1];
            if(matrix[row][col] == 1) {
                ans.push_back(land);
                continue;
            }
            matrix[row][col] = 1;
            land++;
            int nodeID = (row*m) + col;
            for(int i = 0; i < 4; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) {
                    int childID = (nrow * m) + ncol;
                    if (matrix[nrow][ncol] == 1 && ds.findUParent(nodeID) != ds.findUParent(childID)) {
                        ds.unionBySize(nodeID, childID);
                        land--; // Update land after the union operation.
                    }
                }
            }
            ans.push_back(land);
        }
        
        return ans;
        
    }
};