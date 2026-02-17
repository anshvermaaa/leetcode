class Solution {
public:
    vector<int> dp;
    int f(vector<int>& nums,int i){
        if(i<0) return 0;
        if(dp[i]!=-1) return dp[i];
        int take=nums[i]+f(nums,i-2);
        int notTake=f(nums,i-1);
        return dp[i]=max(take,notTake);
    }
    int rob(vector<int>& nums) {
        vector<int> nums1;
        vector<int> nums2;
        int n=nums.size();
        if(n==1) return nums[0];
        for(int i=0;i<n;i++){
            if(i!=0) nums1.push_back(nums[i]);
            if(i!=n-1) nums2.push_back(nums[i]);
        }
        dp.resize(n,-1);
        int firstTake=f(nums1,n-2);
        dp.clear();
        dp.resize(n,-1);
        int lastTake=f(nums2,n-2);
        return max(firstTake,lastTake);
    }
};