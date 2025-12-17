class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            unordered_set<char> visC;
            unordered_set<char> visR;
            for(int j=0;j<9;j++){
                if(visC.count(board[i][j])||visR.count(board[j][i])) return false;
                if(board[j][i]!='.') visR.insert(board[j][i]);
                if(board[i][j]!='.') visC.insert(board[i][j]);
            }
            // for each boxes
            for(int i=0;i<8;i=i+3){
                for(int j=0;j<8;j=j+3){
                    unordered_set<int> vis;
                    for(int di=0;di<3;di++){
                        for(int dj=0;dj<3;dj++){
                            if(vis.count(board[i+di][j+dj])) return false;
                            if(board[i+di][j+dj]!='.') vis.insert(board[i+di][j+dj]);
                        }
                    }
                }
            }
        }
        return true;
    }
};