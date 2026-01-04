class Solution {
public:
    int f(int n){
        if(n==0) return 0;
        int sum=0;
        int l=sqrt(n);
        int cnt=0;
        for(int i=1;i<=l;i++){
            if(n%i==0){
                sum+=i;
                cnt++;
                if(n/i!=i){
                    sum+=(n/i);
                    cnt++;
                }
            }
            if(cnt>4) return 0;
        }
        if(cnt==4) return sum;
        else return 0;
    }
    int sumFourDivisors(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=f(nums[i]);
        }
        return sum;
    }
};