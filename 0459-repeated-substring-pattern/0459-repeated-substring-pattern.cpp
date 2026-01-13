class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n=s.size();
        for(int l=1;l<=(n/2);l++){
            int subStrLen=l;
            if(n%l!=0) continue;
            string temp=s.substr(0,subStrLen);
            for(int i=0;i<n;i=i+subStrLen){
                if(temp==s.substr(i,subStrLen)&&i==(n-subStrLen)) return true;
                else if(temp==s.substr(i,subStrLen)) continue;
                else break;
            }
        }
        return false;
    }
};