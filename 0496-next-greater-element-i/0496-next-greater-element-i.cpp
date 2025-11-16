class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> arr;
        unordered_map<int,int> mp;
        stack<int> st;
        for(int i=nums2.size()-1;i>=0;i--){
            while(st.size()&&st.top()<=nums2[i]) st.pop();
            if(st.size()) mp[nums2[i]]=st.top();
            else mp[nums2[i]]=-1;
            st.push(nums2[i]);
        }
        for(auto el:nums1){
            arr.push_back(mp[el]);
        }
        return arr;
    }
};