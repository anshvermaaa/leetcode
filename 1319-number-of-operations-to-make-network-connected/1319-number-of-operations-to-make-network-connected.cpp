class DSU{
    vector<int> rank,par;
public:
    DSU(int n){
        rank.resize(n,0);
        par.resize(n);
        for(int i=0;i<n;i++){
            par[i]=i;
        }
    }
    int findPar(int n){
        if(n==par[n]) return n;
        return par[n]=findPar(par[n]);
    }
    void unionByRank(int n1,int n2){
        int parN1=findPar(n1);
        int parN2=findPar(n2);
        if(parN1==parN2) return;
        if(rank[parN1]>rank[parN2]){
            rank[parN1]++;
            par[parN2]=parN1;
        }else{
            rank[parN2]++;
            par[parN1]=parN2;
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DSU dsu(n);
        int extraWires=0;
        for(auto &it:connections){
            int parN1=dsu.findPar(it[0]);
            int parN2=dsu.findPar(it[1]);
            if(parN1==parN2) extraWires++;
            else dsu.unionByRank(it[0],it[1]);
        }
        unordered_set<int> par;
        for(int i=0;i<n;i++){
            par.insert(dsu.findPar(i));
        }
        int computerGroups=par.size();
        if(extraWires<(computerGroups-1)) return -1;
        else return computerGroups-1;
    }
};