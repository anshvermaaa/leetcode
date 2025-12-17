class Solution {
public:
    void f(int k,int sum,vector<vector<int>>&anss,vector<int>&ans,int i){
        if(k<0) return;
        if(i==10){
            if(k==0&&sum==0) anss.push_back(ans);
            return;
        }
        // take
        sum-=i;
        ans.push_back(i);
        f(k-1,sum,anss,ans,i+1);
        ans.pop_back();
        sum+=i;
        //not take
        f(k,sum,anss,ans,i+1);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> anss;
        vector<int> ans;
        f(k,n,anss,ans,1);
        return anss;
    }
};