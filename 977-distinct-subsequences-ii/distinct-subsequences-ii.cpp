class Solution {
public:
    int mod = 1e9 + 7;
    int dp[2005];
    int f(int i, const vector<int> &prev) {
        if (i < 0) return 1;
        if (dp[i] != -1) return dp[i];
        long long total = 2LL * f(i - 1, prev) % mod;
        long long duplicate = (prev[i] != -1) ? f(prev[i] - 1, prev) : 0;
        return dp[i] = (total - duplicate + mod) % mod;
    }

    int distinctSubseqII(string s) {
        int n = s.size();
        memset(dp, -1, sizeof(dp));

        vector<int> prev(n);
        vector<int> last(26, -1); // Fix 1: Initialize to -1

        for (int i = 0; i < n; i++) {
            int idx = s[i] - 'a';
            prev[i] = last[idx];
            last[idx] = i;
        }

        return (f(n - 1, prev) - 1 + mod) % mod;
    }
};