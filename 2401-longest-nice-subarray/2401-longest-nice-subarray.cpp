class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        long long int currSum=0,currXor=0;
        int l=0,r=0,len=0;
        while(r<nums.size()){
            currSum+=(long long int)nums[r];
            currXor^=(long long int)nums[r];
            if(l<=r&&currSum!=currXor){
                currSum-=(long long int)nums[l];
                currXor^=(long long int)nums[l];
                l++;
            }
            if(currSum==currXor) len=max(len,r-l+1);
            r++;
        }
        return len;
    }
};