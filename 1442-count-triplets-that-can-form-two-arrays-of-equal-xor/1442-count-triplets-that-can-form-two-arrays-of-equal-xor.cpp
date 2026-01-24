class Solution {
public:
    int countTriplets(vector<int>& arr) {
        vector<int> preXor;
        int preX=0;
        for(auto &el:arr){
            preX^=el;
            preXor.push_back(preX);
        }
        int n=arr.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                for(int k=i;k<=j;k++){
                    if(i==k) continue;
                    int xorTillK=preXor[k]^(i>0?preXor[i-1]:0);
                    int xorAfterK=preXor[j]^preXor[k];
                    if(xorTillK==xorAfterK) cnt++;
                }
            }
        }
        return cnt;
    }
};