class Solution {
public:
    bool canGiveMinProducts(vector<int>& quantities,int n,int mid){
        if(mid==0) return false;
        for(int i=0;i<quantities.size();i++){
            n-=ceil(1.00*quantities[i]/mid);
        }
        return n>=0;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int lo=0;
        int hi=*max_element(quantities.begin(),quantities.end());
        int ans=-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(canGiveMinProducts(quantities,n,mid)){
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return ans;
    }
};