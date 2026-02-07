class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.size();
        vector<int> freqARight(n,0);
        vector<int> freqBLeft(n,0);
        for(int i=1;i<n;i++){
            if(s[i-1]=='b'){
                freqBLeft[i]+=(1+freqBLeft[i-1]);
            }
            else{
                freqBLeft[i]+=freqBLeft[i-1];
            }
        }
        for(int i=n-2;i>=0;i--){
            if(s[i+1]=='a'){
                freqARight[i]+=(1+freqARight[i+1]);
            }
            else{
                freqARight[i]+=freqARight[i+1];
            }
        }
        int ans=1e9;
        for(int i=0;i<n;i++){
            ans=min(ans,freqARight[i]+freqBLeft[i]);
        }
        return ans;
    }
};