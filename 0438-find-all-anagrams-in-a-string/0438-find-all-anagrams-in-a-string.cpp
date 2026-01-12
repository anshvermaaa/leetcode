class Solution {
    bool isAnagram(unordered_map<char,int>&mp1,unordered_map<char,int>&mp2){
        for(auto &it:mp1){
            if(mp2[it.first]!=it.second) return false;
        }
        return true;
    }
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        unordered_map<char,int> mp1;
        unordered_map<char,int> mp2;
        if(s.size()<p.size()) return {};
        int k=p.size();
        int n=s.size();
        for(int i=0;i<k;i++){
            mp1[p[i]]++;
            mp2[s[i]]++;
        }
        int l=0,r=k-1;
        while(r<n){
            if(isAnagram(mp1,mp2)) ans.push_back(l);
            mp2[s[l]]--;
            l++;
            r++;
            mp2[s[r]]++;
        }
        return ans;
    }
};