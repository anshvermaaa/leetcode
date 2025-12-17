class Solution {
public:
    bool isSafe(vector<string>&ans,int idxI,int idxJ){
        int i=idxI;
        int j=idxJ;
        while(i>=0){
            if(ans[i][j]=='Q') return false;
            i--;
        }
        i=idxI;
        while(i>=0&&j>=0){
            if(ans[i][j]=='Q') return false;
            i--;
            j--;
        }
        i=idxI;
        j=idxJ;
        while(i>=0&&j<ans.size()){
            if(ans[i][j]=='Q') return false;
            i--;
            j++;
        }
        return true;
    }
    void f(vector<string>&ans,vector<vector<string>>&answers,int i,int j,int n){
        if(i==n){
            answers.push_back(ans);
            return;
        }
        if(j>=n) return;
        // take
        if(isSafe(ans,i,j)){
            ans[i][j]='Q';
            f(ans,answers,i+1,0,n);
            ans[i][j]='.';
        }
        // not take
        f(ans,answers,i,j+1,n);

    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> answers;
        vector<string> ans(n,string(n,'.'));
        f(ans,answers,0,0,n);
        return answers;
    }
};