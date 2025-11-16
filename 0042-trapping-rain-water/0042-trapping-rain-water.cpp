class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> lMax(height.size(),-1);
        vector<int> rMax(height.size(),-1);
        int pMax=height[0];
        for(int i=0;i<height.size();i++){
            pMax=max(pMax,height[i]);
            lMax[i]=pMax;
        }
        int nMax=height[height.size()-1];
        for(int i=height.size()-1;i>=0;i--){
            nMax=max(nMax,height[i]);
            rMax[i]=nMax;
        }
        int total=0;
        for(int i=0;i<height.size();i++){
            total+=min(lMax[i],rMax[i])-height[i];
        }
        return total;
    }
};