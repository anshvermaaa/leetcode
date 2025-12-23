class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // Brute force solution
        int n=nums.size();
        k=k%n;
        // vector<int> temp;
        // if(k==0) return;
        // for(int i=n-1;i>=n-k;i--){
        //     temp.push_back(nums[i]);
        // }
        // for(int i=n-k-1;i>=0;i--){
        //     nums[i+k]=nums[i];
        // }
        // for(int i=k-1;i>=0;i--){
        //     nums[i]=temp[k-i-1];
        // }
        // optimized version
        reverse(nums.begin(),nums.end()-k);
        reverse(nums.end()-k,nums.end());
        reverse(nums.begin(),nums.end());
        return;
    }
};