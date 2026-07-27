class Solution {
public:
    int lengthOfLastWord(string s) {
        int right = s.size()-1;
        while(s[right]==' ') right--;

        int counter = 0;
        while(right>=0 && s[right]!=' '){
            right--;
            counter++;
        }
        return counter;
    }
};