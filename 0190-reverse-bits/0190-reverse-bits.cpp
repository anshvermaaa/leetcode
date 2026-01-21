class Solution {
public:
    int reverseBits(int n) {
        int ans=0;
        int i=31,j=0;
        while(i>=0&&j<32){
            if(n&(1<<j)) // jth set bit
            {
                ans=ans|(1<<i);
            }
            j++;
            i--;
        }
        return ans;
    }
};