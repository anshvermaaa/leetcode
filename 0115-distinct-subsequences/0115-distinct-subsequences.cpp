class Solution {
public:
    int f(string s, string t,int i,int j,vector<vector<int>>&dp){
        if(j<0) return 1;
        if(i<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]){
            return dp[i][j]=f(s,t,i-1,j-1,dp)+f(s,t,i-1,j,dp);
        }
        return dp[i][j]=f(s,t,i-1,j,dp);
    }
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<double> dp(m+1,0);
        dp[0]=1;
        for(int i=1;i<=n;i++){
            vector<double> curr(m+1,0);
            curr[0]=1;
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                    curr[j]=dp[j-1]+dp[j];
                }else{
                    curr[j]=dp[j];
                }
            }
            dp=curr;
        }
        return (int)dp[m];
    }
};