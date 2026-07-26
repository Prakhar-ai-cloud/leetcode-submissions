class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        string temp = to_string(x);
        int left = 0;
        int right = temp.size()-1;
        while(left<right){
            if(temp[left]!=temp[right]) return false;
            left++;
            right--;
        }
        return true;
    }
};