class Solution {
public:
    string reversePrefix(string word, char ch) {
        int count = 0;
        for(int i=0;i<word.size();i++){
            if(word[i]!=ch) count++;
            else{
                reverse(word.begin(),word.begin()+count+1);
                break;
            }
        }
        return word;
    }
};