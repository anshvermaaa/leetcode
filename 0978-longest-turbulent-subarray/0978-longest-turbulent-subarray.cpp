class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n=arr.size();
        if(n==1) return n;
        int len=1;
        int l=0,r=1;
        int nextOp=0; // 0->dec, 1->inc
        while(r<n){
            if(nextOp==0&&arr[r]<arr[r-1]){
                nextOp=1;
            }else if(nextOp==0&&arr[r]>arr[r-1]){
                nextOp=0;
                l=r-1;
            }
            else if(nextOp==1&&arr[r]>arr[r-1]){
                nextOp=0;
            }else if(nextOp==1&&arr[r]<arr[r-1]){
                l=r-1;
                nextOp=1;
            }
            else{
                l=r;
            }
            len=max(len,r-l+1);
            r++;
        }
        return len;
    }
};