class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        if(n1>n2) return findMedianSortedArrays(nums2,nums1);
        int lo=0;
        int n=(n1+n2);
        int left=(n1+n2+1)/2;
        int hi=n1;
        while(lo<=hi){
            int mid1=lo+(hi-lo)/2;
            int mid2=left-mid1;
            int l1=INT_MIN;
            int r1=INT_MAX;
            int l2=INT_MIN;
            int r2=INT_MAX;
            if(mid1-1>=0) l1=nums1[mid1-1];
            if(mid2-1>=0) l2=nums2[mid2-1];
            if(mid1<n1) r1=nums1[mid1];
            if(mid2<n2) r2=nums2[mid2];

            if(r1>=l2&&r2>=l1) {
                if(n%2==1) return max(l1,l2);
                return (double)(max(l1,l2)+min(r1,r2))/2.0;
            }
            else if(l1>r2) hi=mid1-1;
            else lo=lo+1; 
        }
        return 0;
    }
};