class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int l=0;
        int r=nums.size()-1;
        int maxSum=INT_MIN;
        while(l<r){
            maxSum=max(maxSum,nums[l]+nums[r]);
            l++;
            r--;
        }
        return maxSum;
    }
};