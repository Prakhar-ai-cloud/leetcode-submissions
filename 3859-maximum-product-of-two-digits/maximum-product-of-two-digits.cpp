class Solution {
public:
    int maxProduct(int n) {
        int max = 0;
        int secondmax;
        while(n>=1){
            int a = n%10;
            if(a>=max){
                secondmax = max;
                max = a;
            }
            else if(a >= secondmax) secondmax = a;
            n/=10;
        }
        return max*secondmax;
    }
};