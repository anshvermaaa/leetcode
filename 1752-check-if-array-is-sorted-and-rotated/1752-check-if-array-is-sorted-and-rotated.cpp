class Solution {
public:
    bool check(vector<int>& nums) {
        bool rotated=false;
        int n=nums.size();
        if(n<=2) return true;
        if(nums[0]>=nums[n-1]) rotated=true;
        int count=0;
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]) count++;
            if(count>1) return false;
        }
        if(count>1||(count>0&&!rotated)) return false;
        else return true;
    }
};