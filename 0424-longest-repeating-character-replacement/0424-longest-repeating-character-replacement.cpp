class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> mp; //freq map
        int l=0;
        int r=0;
        int maxFreq=0;
        int len=0;
        while(r<s.size()){
            mp[s[r]]++;
            maxFreq=max(maxFreq,mp[s[r]]);
            if(r-l+1-maxFreq>k){
                mp[s[l]]--;
                if(mp[s[l]]==0) mp.erase(s[l]);
                // updation max freq
                for(auto &it:mp){
                    maxFreq=max(maxFreq,it.second);
                }
                l++;
            }
            len=max(len,r-l+1);
            r++;
        }
        return len;
    }
};