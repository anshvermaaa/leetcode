class Solution {
public:
    bool isSubSequence(string &s1,string &s2,vector<int>& removable,int mid){
        unordered_set<int> deletedIdx;
        for(int i=0;i<mid;i++){
            deletedIdx.insert(removable[i]);
        }
        int n1=s1.size();
        int n2=s2.size();
        int i=0,j=0;
        while(i<n1&&j<n2){
            if(!deletedIdx.count(i)&&s1[i]==s2[j]) j++;
            i++;
        }
        if(j==n2) return true;
        return false;
    }
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int lo=0;
        int hi=removable.size();
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(isSubSequence(s,p,removable,mid)) lo=mid+1;
            else hi=mid-1;
        }
        return hi;
    }
};