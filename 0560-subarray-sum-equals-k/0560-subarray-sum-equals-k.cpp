class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0]=1;
        int preSum=0;
        int cnt=0;
        for(auto el:nums){
            preSum+=el;
            if(mp.count(preSum-k)){
                cnt+=mp[preSum-k];
            }
            mp[preSum]++;
        }
        return cnt;
    }
};