class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n=nums.size();
        int ans=1e9;
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                ans=min(ans,nums[0]+nums[i+1]+nums[j+1]);
            }
        }
        return ans;
    }
};