/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int bs(int target, MountainArray &mountainArr,int lo,int hi,bool left){
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(mountainArr.get(mid)==target) return mid;
            else if(mountainArr.get(mid)>target){
                if(left) hi=mid-1;
                else lo=mid+1;
            }
            else{
                if(left) lo=mid+1;
                else hi=mid-1;
            }
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n=mountainArr.length();
        int lo=1;
        int hi=n-2;
        int peakIdx=-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            int midVal=mountainArr.get(mid);
            int midLeftval=mountainArr.get(mid-1);
            int midRightval=mountainArr.get(mid+1);
            if(midLeftval<midVal&&midVal>midRightval)
            {
                peakIdx=mid;
            }
            if(midVal<=midRightval) lo=mid+1;
            else hi=mid-1;
        }
        if(peakIdx==-1) return bs(target,mountainArr,0,n-1,true);
        int leftAns=bs(target,mountainArr,0,peakIdx,true);
        if(leftAns!=-1) return leftAns;
        return bs(target,mountainArr,peakIdx,n-1,false);
    }
};