class Solution {
public:
    const int mod=1e9+7;
    vector<vector<int>> dp;
    const vector<string> ways={"RYR", "RYG", "RGR", "RGY", "YRY", "YRG", "YGR", "YGY", "GRY", "GRG", "GYR", "GYG"};
    int f(int n,int prevStrIdx){
        if(n==0) return 1;
        if(dp[n][prevStrIdx+1]!=-1) return dp[n][prevStrIdx+1];
        int nOfWays=0;
        for(int i=0;i<ways.size();i++){
            if(prevStrIdx==-1||(prevStrIdx!=i&&ways[i][0]!=ways[prevStrIdx][0]&&ways[i][1]!=ways[prevStrIdx][1]&&ways[i][2]!=ways[prevStrIdx][2])){
                nOfWays+=f(n-1,i);
                nOfWays%=mod;
            }
        }
        return dp[n][prevStrIdx+1]=nOfWays%mod;
    }
    int numOfWays(int n) {
        dp.resize(n+1,vector<int>(13,-1));
        return f(n,-1)%mod;
    }
};