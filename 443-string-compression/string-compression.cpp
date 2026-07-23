class Solution {
public:
    int compress(vector<char>& chars) {
        string s;
        if(chars.size()==1) return 1;
        int left = 0;
        int right = 0;
        while(right<chars.size()){
            while(right<chars.size() && chars[right]==chars[left]) right++;
            if(right-left == 1){
                s += chars[left];
            }
            else {
                s+=chars[left];
                s+= to_string(right-left);
            }
            left = right;
        }
        for(int i=0 ; i<s.size();i++){
            chars[i] = s[i];
        }
        return s.size();
    }
};