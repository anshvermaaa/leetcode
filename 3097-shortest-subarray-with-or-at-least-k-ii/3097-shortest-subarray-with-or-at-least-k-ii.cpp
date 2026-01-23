class Solution {
private:
    int getNumber(vector<int> &freq){
        int num=0;
        for(int i=0;i<32;i++){
            if(freq[i]>0) num=num|(1<<i);
        }
        return num;
    }
    void updateFreq(vector<int> &freq,int num,bool remove=false){
        for(int i=0;i<32;i++){
            if(num&(1<<i)){
                if(remove) freq[i]--;
                else freq[i]++;
            }
        }
    }
    
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int len=INT_MAX;
        int l=0,r=0;
        int currentOr=0;
        vector<int> freq(32,0);
        while(r<nums.size()){
            currentOr|=nums[r];
            updateFreq(freq,nums[r],false);
            while(l<=r&&currentOr>=k){
                len=min(len,r-l+1);
                updateFreq(freq,nums[l],true);
                currentOr=getNumber(freq);
                l++;
            }
            r++;
        }
        return len==INT_MAX?-1:len;
    }
};