class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k%=n;
        vector<int> ans=nums;
        for(int i=0;i<n;i++){
            ans[i]=nums[(i-k+n)%n];
        }
        nums=ans;
    }
};