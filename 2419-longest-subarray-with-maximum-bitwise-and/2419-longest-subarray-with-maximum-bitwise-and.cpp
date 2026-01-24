class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int idx=-1;
        int maxEl=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(maxEl<nums[i]){
                maxEl=nums[i];
                idx=i;
            }
        }
        int len=0;
        int maxLen=0;
        while(idx<n){
            if(maxEl==nums[idx]) len++;
            else{
                maxLen=max(maxLen,len);
                len=0;
            }
            idx++;
        }
        maxLen=max(maxLen,len);
        return maxLen;
    }
};