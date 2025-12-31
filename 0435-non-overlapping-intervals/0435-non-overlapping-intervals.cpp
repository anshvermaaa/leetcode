class Solution {
public:
    static bool comp(const vector<int>&a,const vector<int>&b){
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end(),comp);
        int end=INT_MIN,cnt=0;
        for(int i=0;i<arr.size();i++){
            if(end<=arr[i][0]){
                cnt++;
                end=arr[i][1];
            }
        }
        return arr.size()-cnt;
    }
};