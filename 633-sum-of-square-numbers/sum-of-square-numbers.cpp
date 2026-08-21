class Solution {
public:
    bool judgeSquareSum(int c) {
        vector<long long> squares;
        squares.push_back(0);
        for(long long i=1;i*i<=c ; i++){
            squares.push_back(i*i);
        }
        int n = squares.size();
        int left = 0;
        int right = n-1;
        while(left <= right){
            if(squares[left]+squares[right] == c) return true;
            else if(squares[left]+squares[right] > c) right--;
            else left ++;
        }
        return false;
    }
};