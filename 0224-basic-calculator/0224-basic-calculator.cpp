class Solution {
public:
    typedef long long ll;
    int calculate(string s) {
        int n=s.size();
        ll num=0,res=0,sign=1;
        stack<int> st;
        for(int i=0;i<n;i++){
            if(s[i]>='0'&&s[i]<='9'){
                num=num*10+(s[i]-'0');
            }
            else if(s[i]=='+'){
                res+=(num*sign);
                sign=1;
                num=0;
            }
            else if(s[i]=='-'){
                res+=(num*sign);
                sign=-1;
                num=0;
            }else if(s[i]=='('){
                st.push(res);
                st.push(sign);
                num=0;
                res=0;
                sign=1;
            }
            else if(s[i]==')'){
                res+=num*sign; // prevVal
                int stSign=st.top();
                st.pop();
                int prevRes=st.top();
                st.pop();
                res=prevRes+(stSign*res);
                num=0;
            }
        }
        if(num) res+=(num*sign);
        return (int)res;
    }
};