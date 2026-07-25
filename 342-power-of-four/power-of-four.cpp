class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n==1) return true;
        if(n<4) return false;
        int count = 0;
        while(n%4==0) n/=4;
        return n==1;
    }
};