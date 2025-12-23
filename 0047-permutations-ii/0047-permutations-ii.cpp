class Solution {
public:
    void f(vector<int>& nums,vector<vector<int>>&anss,vector<int>&ans,int i){
        if(i==nums.size()){
            anss.push_back(ans);
            return;
        }
        unordered_set<int> vis;
        for(int idx=i;idx<nums.size();idx++){
            if(!vis.count(nums[idx])){
                vis.insert(nums[idx]);
                ans.push_back(nums[idx]);
                swap(nums[i],nums[idx]);
                f(nums,anss,ans,i+1);
                ans.pop_back();
                swap(nums[i],nums[idx]);
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> anss;
        vector<int> ans;
        f(nums,anss,ans,0);
        return anss;
    }
};