class Solution {
public:
    int productf(int copy){
        int product = 1;
        while(copy > 0){
            int a = copy%10;
            product *= a;
            copy/=10;
        }
        return product;
    }
    int smallestNumber(int n, int t) {
        int lastdig = n%10;
        if(lastdig == 0){
            return n;
        }
        int remaining = 10 - lastdig + 1;
        for(int i=0;i<remaining ; i++){
            int copy = n;
            copy += i;
            if(productf(copy)%t == 0){
                return copy;
            }
        }
        return 0;
    }
};