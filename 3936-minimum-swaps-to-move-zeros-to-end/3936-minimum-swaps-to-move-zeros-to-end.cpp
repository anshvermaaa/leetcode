class Solution {
    int f(vector<int>& nums) {
        int i=0;
        int cnt=0;
        int n=nums.size();
        int j=n-1;
        while(i<j){
            if(nums[i]==0&&nums[j]!=0){
                cnt++;
                swap(nums[i],nums[j]);
                i++;
                j--;
            }
            while(i<j&&nums[i]!=0) i++;
            while(i<j&&nums[j]==0) j--; 
        }
        return cnt;
    }
public:
    int minimumSwaps(vector<int>& nums) {
        return f(nums);
    }
};