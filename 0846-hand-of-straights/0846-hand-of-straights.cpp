class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if(n%groupSize!=0) return false;
        int numberOfGroups=n/groupSize;
        map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[hand[i]]++;
        }
        while(numberOfGroups&&mp.size()){
            int currEl=mp.begin()->first;
            mp[currEl]--;
            if(mp[currEl]==0) mp.erase(currEl);
            for(int i=1;i<groupSize;i++){
                if(!mp.count(currEl+1)) return false;
                mp[currEl+1]--;
                if(mp[currEl+1]==0) mp.erase(currEl+1);
                currEl++;
            }
            numberOfGroups--;
        }
        return true;
    }
};