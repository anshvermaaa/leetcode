class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        vector<int> ans(nums.size(),-1);
        for(int i=nums.size()-2;i>=0;i--) st.push(nums[i]);
        for(int i=nums.size()-1;i>=0;i--){
            while(st.size()&&st.top()<=nums[i]) st.pop();
            if(st.size()) ans[i]=st.top();
            st.push(nums[i]);
        }
        return ans;
    }
};