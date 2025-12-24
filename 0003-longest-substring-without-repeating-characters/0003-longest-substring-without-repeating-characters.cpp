class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       unordered_map<char,int> mp;
       int l=0,r=0,len=0,n=s.size();
       while(r<n){
        if(mp.count(s[r])){
            if(mp[s[r]]>=l){
                l=mp[s[r]]+1;
            }
        }
        len=max(len,r-l+1);
        mp[s[r]]=r;
        r++;
       } 
       return len;
    }
};