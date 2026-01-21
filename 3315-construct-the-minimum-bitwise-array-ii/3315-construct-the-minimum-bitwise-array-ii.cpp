class Solution {
    int f(int k){
        int cnt=0;
        for(int i=0;i<32;i++){
            if(k&(1<<i)) cnt++;
            else break;
        }
        return k-pow(2,cnt-1);
    }
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            if(nums[i]==2) ans[i]=-1;
            else ans[i]=f(nums[i]);
        }
        return ans;
    }
};