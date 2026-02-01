class Solution {
public:
    int minOperations(vector<int>& nums) {
        int cnt=0;
        int n=nums.size();
        for(int i=0;i<n-2;i++){
            if(nums[i]==0){
                // flip
                nums[i]^=1;
                nums[i+1]^=1;
                nums[i+2]^=1;
                cnt++;
            }
        }
        if(nums[n-1]==0||nums[n-2]==0||nums[n-3]==0) return -1;
        return cnt;
    }
};