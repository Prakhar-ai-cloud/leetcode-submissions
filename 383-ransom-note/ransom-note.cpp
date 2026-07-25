class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> note;
        unordered_map<char,int> maga;
        for(int i=0;i<ransomNote.size();i++){
            note[ransomNote[i]]++;
        }
        for(int i=0;i<magazine.size();i++){
            maga[magazine[i]]++;
        }
        for(auto &it:note){
            char a = it.first;
            int b = it.second;
            if(maga[a]>=b) continue;
            else return false;
        }
        return true;
    }
};