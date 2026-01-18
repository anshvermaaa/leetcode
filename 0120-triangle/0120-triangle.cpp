class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int m=triangle[n-1].size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=n-1;i>=0;i--){
            for(int j=triangle[i].size()-1;j>=0;j--){
                int jth=triangle[i][j]+dp[i+1][j];
                int jPlus1th=triangle[i][j]+dp[i+1][j+1];
                dp[i][j]=min(jth,jPlus1th);
            }
        }
        return dp[0][0];
    }
};