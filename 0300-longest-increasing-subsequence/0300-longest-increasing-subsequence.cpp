class Solution {
public:
    int f(vector<int>& nums,int i,int prevIdx,vector<vector<int>>&dp){
        if(i==nums.size()) return 0;
        if(dp[i][prevIdx+1]!=-1) return dp[i][prevIdx+1];
        int l=0;
        if(prevIdx==-1||nums[prevIdx]<nums[i]){
            l=1+f(nums,i+1,i,dp);
        }
        l=max(l,f(nums,i+1,prevIdx,dp));
        return dp[i][prevIdx+1]=l;
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+1,vector<int>(nums.size()+2,-1));
        return f(nums,0,-1,dp);
    }
};