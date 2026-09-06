class Solution {
public:
    int dp[1005][1005];
    int solver(int i, int j, string &s, string &t){
        if(i>= s.size()) return j>= t.size();
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        ans += solver(i+1, j,s,t);
        if(s[i] == t[j]) ans += solver(i+1,j+1, s,t);
        return dp[i][j] = ans;
    }
    int numDistinct(string s, string t) {
        memset(dp,-1,sizeof(dp));
        return solver(0,0,s,t);
    }
};