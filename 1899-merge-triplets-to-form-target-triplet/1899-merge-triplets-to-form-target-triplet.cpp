class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> triplet(3,-1);
        for(auto &tp:triplets){
            if(tp[0]<=target[0]&&tp[1]<=target[1]&&tp[2]<=target[2]){
                triplet[0]=max(triplet[0],tp[0]);
                triplet[1]=max(triplet[1],tp[1]);
                triplet[2]=max(triplet[2],tp[2]);
            }
        }
        if(triplet[0]==target[0]&&triplet[1]==target[1]&&triplet[2]==target[2]) return true;
        return false;
    }
};