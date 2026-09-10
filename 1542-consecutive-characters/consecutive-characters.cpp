class Solution {
public:
    int maxPower(string s) {
        char prev = '.';
        int n = s.size();
        int count = 0;
        int ans = 0;
        for(int i=0;i<n;i++){
            if(s[i] == prev) count++;
            else{
                prev = s[i];
                ans = max(ans,count);
                count = 1;
            }
        }
        ans = max(ans,count);
        return ans;
    }
};