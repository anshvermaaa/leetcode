class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int ans=0;
        vector<int> nsi(arr.size(),arr.size());
        vector<int> psi(arr.size(),-1);
        stack<int> st;
        for(int i=arr.size()-1;i>=0;i--){
            while(st.size()&&arr[st.top()]>arr[i]) st.pop();
            if(st.size()) nsi[i]=st.top();
            st.push(i);
        }
        while(st.size()) st.pop();
        for(int i=0;i<arr.size();i++){
            while(st.size()&&arr[st.top()]>=arr[i]) st.pop();
            if(st.size()) psi[i]=st.top();
            st.push(i);
        }
        int mod=1e9+7;
        for(int i=0;i<arr.size();i++){
            ans = (ans + 1LL * arr[i] * (i - psi[i]) * (nsi[i] - i)) % mod;
        }
        return ans%mod;
    }
};