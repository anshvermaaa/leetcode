class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char,int> freq;
        for(auto &ch:s) freq[ch]++;
        unordered_set<char> vis;
        stack<char> st;
        string ans="";
        for(char &ch:s){
            freq[ch]--;
            if (vis.count(ch)) continue;
            while(st.size()&&st.top()>ch&&freq[st.top()]>0){
                vis.erase(st.top());
                st.pop();
            }
            if(!vis.count(ch)) st.push(ch);
            vis.insert(ch);
        }
        while(st.size()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};