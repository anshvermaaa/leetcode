class Solution {
public:
    bool canEat(vector<int>& piles,int k,int h){
        for(int i=0;i<piles.size();i++){
            h-=(piles[i]/k);
            if(piles[i]%k!=0) h--;
        }
        return h>=0;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo=1;
        int hi=*max_element(piles.begin(),piles.end());
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(canEat(piles,mid,h)) hi=mid-1;
            else lo=mid+1;
        }
        return lo;
    }
};