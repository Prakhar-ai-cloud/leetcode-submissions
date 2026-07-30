class Solution {
public:
    bool detectCapitalUse(string word) {
        int uppercase = 0;
        for(int i = 0 ; i<word.size();i++){
            if(word[i]>='A'&&word[i]<='Z') uppercase++;
        }
        if(uppercase==0 || uppercase == word.size() || (uppercase == 1 && (word[0]<='Z'&&word[0]>='A'))) return true;
        return false;
    }
};