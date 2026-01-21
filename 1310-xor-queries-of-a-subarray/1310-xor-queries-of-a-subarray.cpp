class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans(queries.size());
        vector<int> prefXor(arr.size());
        int pXor=0;
        for(int i=0;i<arr.size();i++){
            pXor^=arr[i];
            prefXor[i]=pXor;
        }
        for(int i=0;i<queries.size();i++){
            int l=queries[i][0];
            int r=queries[i][1];
            ans[i]=(prefXor[r]^(l-1>=0?prefXor[l-1]:0));
        }
        return ans;
    }
};