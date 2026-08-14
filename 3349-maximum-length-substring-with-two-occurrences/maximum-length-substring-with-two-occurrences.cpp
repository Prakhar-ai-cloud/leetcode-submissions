class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        int max_ans = 0;
        for(int i=0;i<n;i++){
            unordered_map<char,int> mp;
            int count = 0;
            for(int j=i;j<n;j++){
                if(!mp.count(s[j])||mp[s[j]] < 2){
                    mp[s[j]]++;
                    count++;
                }
                else if(mp[s[j]]==2){
                    break;
                }
            }
            max_ans = max(count,max_ans);
        }
        return max_ans;
    }
};