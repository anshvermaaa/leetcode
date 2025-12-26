class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<int,char>> pq; // freq->character    
        unordered_map<char,int> mp;  
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        for(auto p:mp){
            pq.push({p.second,p.first});
        }
        string ans="";
        while(pq.size()>0){
            auto [f,ch]=pq.top();
            pq.pop();
            for(int i=0;i<f;i++){
                ans+=ch;
            }
        }
        return ans;
    }
};