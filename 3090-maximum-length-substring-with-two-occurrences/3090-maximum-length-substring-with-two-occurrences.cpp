class Solution {
public:
    int maximumLengthSubstring(string s) {
       int l=0,r=0;
       int n=s.size();
       int len=0;
       vector<int> freq(26,0);
        while(r<n){
            freq[s[r]-'a']++;
            while(freq[s[r]-'a']>2){
                freq[s[l]-'a']--;
                l++;
            }
            len=max(len,r-l+1);
            r++;
        }
        return len;
    }
};