class Solution {
public:
    bool dfs(int node,vector<vector<int>>& graph,vector<bool> &vis,vector<bool> &pathVis,vector<bool> &isSafe){
        vis[node]=true;
        pathVis[node]=true;
        for(auto it:graph[node]){
            if(!vis[it]){
                if(dfs(it,graph,vis,pathVis,isSafe)) return true;// if cycle
            }
            else if(pathVis[it]) return true;
        }
        pathVis[node]=false;
        isSafe[node]=true;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<bool> vis(n,false);
        vector<bool> pathVis(n,false);
        vector<bool> isSafe(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,graph,vis,pathVis,isSafe);
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(isSafe[i]) ans.push_back(i);
        }
        return ans;
    }
};