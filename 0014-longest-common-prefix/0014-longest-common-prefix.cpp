struct Node{
    vector<Node*> links;
    int cnt;
    int en;
    Node(){
        links.resize(26,NULL);
        cnt=0;
        en=0;
    }
};
class Solution {
    Node* root;
public:
    Solution(){
        root=new Node();
    }
    string longestCommonPrefix(vector<string>& strs) {
        for(auto str:strs){
            Node* temp=root;
            for(auto ch:str){
                if(temp->links[ch-'a']!=NULL){
                    temp=temp->links[ch-'a'];
                }else{
                    temp->links[ch-'a']=new Node();
                    temp=temp->links[ch-'a'];
                }
                temp->cnt++;
            }
            temp->en=temp->en+1;
        }
        string ans="";
        int n=strs.size();
        string maxStr=strs[0];
        Node* temp=root;
        for(auto ch:maxStr){
            if(temp->links[ch - 'a'] && temp->links[ch - 'a']->cnt == n){
                temp=temp->links[ch-'a'];
                ans+=ch;
            }
            else return ans;
        }
        return ans;
    }
};