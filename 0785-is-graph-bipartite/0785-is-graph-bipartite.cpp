class Solution {
public:
    bool bfs(vector<vector<int>>& graph,vector<int> &colored,int root){
        queue<int> qu;
        qu.push(root);
        colored[root]=0;
        while(!qu.empty()){
            int currNode=qu.front();
            qu.pop();
            for(auto neighbor:graph[currNode]){
                if(colored[neighbor]==-1){
                    qu.push(neighbor);
                    colored[neighbor]=colored[currNode]==0?1:0;
                }
                else if(colored[neighbor]!=-1&&colored[neighbor]==colored[currNode]) return false;
                else continue;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> colored(n,-1);
        for(int i=0;i<n;i++){
            if(colored[i]==-1){
                bool ans=bfs(graph,colored,i);
                if(!ans) return false;
            }
        }
        return true;
    }
};