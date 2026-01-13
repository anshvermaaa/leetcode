class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int n=board.size();
        int m=board[0].size();
        queue<pair<int,int>> qu;
        qu.push({click[0],click[1]});
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        vis[click[0]][click[1]]=true;
        if(board[click[0]][click[1]]=='M'){
            board[click[0]][click[1]]='X';
            return  board;
        }
        while(!qu.empty()){
            auto [i,j]=qu.front();
            qu.pop();
            if(board[i][j]=='E'){
                int cnt=0;
                for(int dr=-1;dr<2;dr++){
                    for(int dc=-1;dc<2;dc++){
                        int newR=i+dr;
                        int newC=j+dc;
                        if(newR<n&&newC<m&&newR>=0&&newC>=0){
                            if(board[newR][newC]=='M') cnt++;
                        }
                    }
                }
                if(cnt>0){
                    board[i][j]=(char)(cnt+'0');
                }
                else{
                    board[i][j]='B';
                    for(int dr=-1;dr<2;dr++){
                    for(int dc=-1;dc<2;dc++){
                        int newR=i+dr;
                        int newC=j+dc;
                        if(newR<n&&newC<m&&newR>=0&&newC>=0&&!vis[newR][newC]&&board[newR][newC]=='E'){
                            qu.push({newR,newC});
                            vis[newR][newC]=true;
                        }
                    }
                    }
                }
            }
        }
        return board;
    }
};