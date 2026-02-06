class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int i=0;
        int n=nums.size();
        int sum=0;
        bool allNeg=true;
        int maxValIfNeg=-1e9;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            maxValIfNeg=max(maxValIfNeg,nums[i]);
            if(nums[i]>0) allNeg=false;
        }
        if(allNeg) return maxValIfNeg;
        int minSum=1e9;
        int tempSum=0;
        for(int i=0;i<n;i++){
            tempSum+=nums[i];
            minSum=min(minSum,tempSum);
            if(tempSum>0){
                tempSum=0;
            }
        }
        tempSum=0;
        int maxSum=0;
        for(int i=0;i<n;i++){
            tempSum+=nums[i];
            maxSum=max(maxSum,tempSum);
            if(tempSum<0){
                tempSum=0;
            }
        }
        return max(maxSum,sum-minSum);
    }
};