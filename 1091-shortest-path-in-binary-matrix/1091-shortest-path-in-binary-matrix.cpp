class Solution {
public:
    typedef pair<int,pair<int,int>> pp;
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if(grid[0][0]!=0||grid[n-1][m-1]!=0) return -1;
        queue<pp> qu;
        qu.push({1,{0,0}});
        vector<vector<int>> dist(n,vector<int> (m,1e9));
        vector<vector<bool>> vis(n,vector<bool> (m,false));
        dist[0][0]=1;
        vis[0][0]=true;
        while(!qu.empty()){
            auto [dis,node]=qu.front();
            auto [i,j]=node;
            qu.pop();
            for(int ni=-1;ni<=1;ni++){
                for(int nj=-1;nj<=1;nj++){
                    int nr=i+ni;
                    int nc=j+nj;
                    if(nr>=0&&nc>=0&&nr<n&&nc<m&&grid[nr][nc]==0&&!vis[nr][nc]){
                        vis[nr][nc]=true;
                        dist[nr][nc]=dis+1;
                        qu.push({dist[nr][nc],{nr,nc}});
                    }
                }
            }
        }
        if(dist[n-1][m-1]==1e9) return -1;
        return dist[n-1][m-1];
    }
};