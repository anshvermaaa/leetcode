class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> arr;
        for(int i=0;i<nums.size();i++){
            if(i==0) arr.push_back(nums[i]);
            else{
                if(arr[arr.size()-1]<nums[i]) arr.push_back(nums[i]);
                else arr[lower_bound(arr.begin(),arr.end(),nums[i])-arr.begin()]=nums[i];
            }
        }
        return arr.size();
    }
};