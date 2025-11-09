class Solution {
public:
    char reqChar(char c){
        switch(c){
            case '}':
                return '{';
            case ']':
                return '[';
            default:
                return '(';
        }
        return '[';
    }
    bool isValid(string s) {
        if(s.size()%2==1) return false;
        stack<int> st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('||s[i]=='{'||s[i]=='[') st.push(s[i]);
            else{
                char ch=reqChar(s[i]);
                if(st.size()&&st.top()!=ch) return false;
                if(st.size()==0) return false;
                else st.pop();
            }
        }
        return st.size()==0;
    }
};