class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=position.size();
        vector<pair<int,double>> arr(n); // {pos,timeToReach}
        for(int i=0;i<n;i++) arr[i]={position[i],(target-position[i])/(1.0*speed[i])};
        sort(arr.begin(),arr.end());
        int fleets=0;
        for(int i=n-1;i>0;i--){
            if(arr[i].second>=arr[i-1].second){
                arr[i-1]=arr[i];
            }
            else fleets++;
        }
        fleets++;
        return fleets;
    }
};