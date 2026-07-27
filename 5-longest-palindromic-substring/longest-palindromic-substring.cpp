class Solution {
public:
    bool is_palindrome(int i, int j, string& s){
        int left = i;
        int right = j;
        while(left<right){
            if(s[left]!=s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        if(s.size()<=1) return s;
        string answer = s.substr(0,1);
        for(int i=0;i<s.size()-1;i++){
            for(int j=i+1;j<s.size();j++){
                if(is_palindrome(i,j,s)){
                    if(j-i+1 > answer.size()){
                        answer = s.substr(i,j-i+1);
                    }
                }
            }
        }
        return answer;
    }
};