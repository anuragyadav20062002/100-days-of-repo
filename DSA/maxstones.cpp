      int maxrow=0;
        int maxcol=0;
        for(auto it: stones){
            maxrow=max(maxrow,it[0]);
            maxcol=max(maxcol,it[1]);
        }
        DisjointSet ds(maxrow+maxcol+1);
        unordered_map<int,int> stonenodes;
        for(auto it: stones){
            int noderow=it[0];
            int nodecol=maxrow +it[1] +1;
            ds.unionbysize(noderow,nodecol);
            stonenodes[noderow]=1;
            stonenodes[nodecol]=1;
        }
        int count=0;
        for(auto it: stonenodes){
            if(ds.findUltimateParent(it.first)==it.first){
                count++;
            }
        }
        return n-count;