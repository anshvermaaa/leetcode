class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long long maxProd=-1e9;
        long long prod1=1;// for positives
        long long prod2=1;// including negatives because it may happen that two neg will pos
        for(auto el:nums){
            if(el<0) swap(prod1,prod2);
            prod1=max((long long)el,prod1*(long long)el);
            prod2=min((long long)el,prod2*(long long)el);
            maxProd=max(maxProd,prod1);
        }
        return (int)maxProd;
    }
};