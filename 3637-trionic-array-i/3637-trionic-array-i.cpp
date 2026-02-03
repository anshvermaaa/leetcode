class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int i=1;
        int n=nums.size();
        int p=-1;
        int q=-1;
        while(i<n&&nums[i-1]<nums[i]) i++;
        p=i-1;
        while(i<n&&nums[i-1]>nums[i]) i++;
        q=i-1;
        while(i<n&&nums[i-1]<nums[i]){
            i++;
        }
        if(i!=n) return false;
        if(p==-1||q==-1) return false;
        if(p==0||p==q||q==n-1) return false;
        return true;
    }
};