class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k=1;
        int prevEl=nums[0];
        int cnt=1;
        int i=1;
        while(i<nums.size()){
            if(prevEl==nums[i]){
                cnt++;
                if(cnt<=2){ 
                    k++;
                    i++;
                }
                else{
                    nums.erase(nums.begin()+i);
                } 
            }
            else{
                cnt=1;
                prevEl=nums[i];
                k++;
                i++;
            }
        }
        return k;
    }
};