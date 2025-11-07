class Solution {
public:
    double f(vector<int>&arr1,vector<int>&arr2){
        int n1=arr1.size();
        int n2=arr2.size();
        vector<int> arr(n1+n2,0);
        int k=0;
        int i=0;
        int j=0;
        while(i<n1&&j<n2){
            if(arr1[i]<arr2[j]){
                arr[k++]=arr1[i++];
            }else{
                arr[k++]=arr2[j++];
            }
        }
        while(i<n1){
            arr[k++]=arr1[i++];
        }
        while(j<n2) arr[k++]=arr2[j++];
        if(k%2==1) return arr[k/2];
        else return (arr[k/2-1]+arr[k/2])/2.0;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        return f(nums1,nums2);
    }
};