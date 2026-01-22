class Solution {
public:
    char findTheDifference(string s, string t) {
        char xorr='\0';
        for(int i=0;i<s.size();i++){
            xorr^=s[i];
            xorr^=t[i];
        }
        xorr^=t[t.size()-1];
        return xorr;
    }
};