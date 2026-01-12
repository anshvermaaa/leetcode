class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n=points.size();
        int minOps=0;
        for(int i=1;i<n;i++){
            int requiredtoLeft=abs(points[i-1][0]-points[i][0]);
            int requiredtoRight=abs(points[i-1][1]-points[i][1]);
            int ops=(min(requiredtoLeft,requiredtoRight)+abs(requiredtoRight-requiredtoLeft));
            minOps+=ops;
        }
        return minOps;
    }
};