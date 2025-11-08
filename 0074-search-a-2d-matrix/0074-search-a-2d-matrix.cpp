class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int col=matrix[0].size();
        int lo=0;
        int hi=row*col-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            int i=mid/col;
            int j=mid%col;
            if(matrix[i][j]==target) return true;
            else if(matrix[i][j]<target) lo=mid+1;
            else hi=mid-1;
        }
        return false;
    }
};