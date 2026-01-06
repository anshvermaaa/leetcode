class Solution {
public:
    int myAtoi(string s) {
        bool pos=true;
        int i=0;
        long long ans=0;
        while(i<s.size()&&(s[i]==' '||s[i]=='0'||s[i]=='+'||s[i]=='-')){
            if(s[i]=='-') pos=false;
            if(i>0&&s[i]==' '&&s[i-1]!=' ') return 0;
            if((s[i]=='+'||s[i]=='-')&&i>0&&(s[i-1]=='0'||s[i-1]=='-'||s[i-1]=='+')) return 0;
            i++;
        }
        while(i<s.size()&&s[i]<='9'&&s[i]>='0'){
            if(ans>INT_MAX) return pos?INT_MAX:INT_MIN;
            ans=ans*10;
            ans+=(long long)(s[i]-'0');
            i++;
        }
        if(ans>INT_MAX&&pos) return INT_MAX;
        if(ans>INT_MAX&&!pos) return INT_MIN;
        return pos?(int)ans:(int)ans*(-1);
    }
};