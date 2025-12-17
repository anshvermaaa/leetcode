class Solution {
public:
    int cnt=0;
    bool isSafe(vector<vector<int>>&ans,int si,int sj,int n){
        int i=si;
        int j=sj;
        while(i>=0){
            if(ans[i][j]==1) return false;
            i--;
        }
        i=si;
        while(i>=0&&j>=0){
            if(ans[i][j]==1) return false;
            i--;
            j--;
        }
        i=si;
        j=sj;
        while(i>=0&&j<n){
            if(ans[i][j]==1) return false;
            i--;
            j++;
        }
        return true;
    }
    void f(vector<vector<int>>&ans,int i,int j,int n){
        if(i==n) {
            cnt++;
            return;
        }
        if(j>=n) return;
        // take
        if(isSafe(ans,i,j,n)){
            ans[i][j]=1;
            f(ans,i+1,0,n);
            ans[i][j]=0;
        }
        //not take
        f(ans,i,j+1,n);
    }
    int totalNQueens(int n) {
        vector<vector<int>> ans(n,vector<int>(n,0));
        f(ans,0,0,n);
        return cnt;
    }
};