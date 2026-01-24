class Solution {
public:
    static bool comp(pair<int,int> &a,pair<int,int> &b){
        return a.first>b.first;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<pair<int,int>> arr;
        for(int i=0;i<spells.size();i++){
            arr.push_back({spells[i],i});
        }
        sort(arr.begin(),arr.end(),comp);
        sort(potions.begin(),potions.end());
        vector<int> ans(spells.size(),0);
        int i=0,j=0;
        while(i<arr.size()&&j<potions.size()){
            long long mul=1LL*arr[i].first*potions[j];
            if(mul>=(long long)success){
                ans[arr[i].second]=potions.size()-j;
                i++;
            }else j++;
        }
        return ans;
    }
};