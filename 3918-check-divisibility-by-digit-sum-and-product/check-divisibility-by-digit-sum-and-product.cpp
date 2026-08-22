class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int product = 1;
        int copy = n;
        while(n>0){
            sum += n%10;
            product *= n%10;
            n/=10;
        }
        if(copy%(sum+product)==0) return true;
        return false;
    }
};