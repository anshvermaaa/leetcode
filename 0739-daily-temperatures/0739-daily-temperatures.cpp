class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        vector<int> ans(temperatures.size(),0);
        for(int i=temperatures.size()-1;i>=0;i--){
            while(st.size()&&temperatures[st.top()]<=temperatures[i]) st.pop();
            if(st.size()) ans[i]=st.top()-i;
            st.push(i);
        }
        return ans;
    }
};