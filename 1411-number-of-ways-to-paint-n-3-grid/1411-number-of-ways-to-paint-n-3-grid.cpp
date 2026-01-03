class Solution {
public:
    int numOfWays(int n) {
        const int mod=1e9+7;
        if(n==0) return 0;
        long long int a=6;
        long long int b=6;
        for(int i=2;i<=n;i++){
            long long int tempA=(3*a+2*b)%mod;
            long long int tempB=(2*a+2*b)%mod;
            a=tempA;
            b=tempB;
        }
        return (int)((a+b)%mod);
    }
};