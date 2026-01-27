class Solution {
public:
    bool f(vector<int>& nums,int mid,int k){
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=mid){
                cnt++;
                i++;
            }
        }
        return cnt>=k;
    }
    int minCapability(vector<int>& nums, int k) {
        int lo=*min_element(nums.begin(),nums.end());
        int hi=*max_element(nums.begin(),nums.end());
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(f(nums,mid,k)) hi=mid-1;
            else lo=mid+1;
        }
        return lo;
    }
};