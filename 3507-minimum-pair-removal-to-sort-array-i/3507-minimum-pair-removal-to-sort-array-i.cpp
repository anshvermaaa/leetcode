class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int cnt=0;
        while(!is_sorted(nums.begin(),nums.end())){
            int mini=INT_MAX, idx=-1;
            for(int i=0;i<nums.size()-1;i++){
                if(mini>(nums[i]+nums[i+1])){
                    mini=nums[i]+nums[i+1];
                    idx=i;
                }
            }
            nums[idx]+=nums[idx+1];
            nums.erase(nums.begin()+idx+1);
            cnt++;
        }
        return cnt;

    }
};