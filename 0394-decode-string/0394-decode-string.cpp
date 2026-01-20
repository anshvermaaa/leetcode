class Solution {
public:
    string decodeString(string s) {
        stack<string> strSt;
        stack<int> numSt;
        int num=0;
        for(int i=0;i<s.size();i++){
            if(s[i]>='0'&&s[i]<='9'){
                num=num*10+(s[i]-'0');
            }
            else if(s[i]=='['){
                strSt.push("[");
                numSt.push(num);
                num=0;
            }
            else if(s[i]==']'){
                string temp="";
                while(strSt.top()!="["){
                    temp+=strSt.top(); strSt.pop();
                }
                strSt.pop();
                int times=numSt.top();
                numSt.pop();
                string tempStr=temp;
                for(int i=0;i<times-1;i++){
                    temp+=tempStr;
                }
                strSt.push(temp);
            }else{
                strSt.push(string(1,s[i]));
            }
        }
        
        string ans="";
        while(strSt.size()){
            string str=strSt.top(); strSt.pop();
            ans+=str;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};