class Solution {
public:
//         int solve(int left, int right,
//           vector<int>& piles,
//           vector<vector<int>>& dp){

//     if(left == right)
//         return piles[left];

//     if(dp[left][right] != -1)
//         return dp[left][right];

//     int takeLeft =
//         piles[left] - solve(left + 1, right, piles, dp);

//     int takeRight =
//         piles[right] - solve(left, right - 1, piles, dp);

//     return dp[left][right] = max(takeLeft, takeRight);
// }
    bool stoneGame(vector<int>& piles) {
    //         int n = piles.size();
        return true;
    // vector<vector<int>> dp(n, vector<int>(n, -1));

    // return solve(0, n - 1, piles, dp) >= 0;
    }
};