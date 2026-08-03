class Solution {
public:
    int solve(int index, vector<int>& stoneValue, vector<int>& dp){
        if(index >= stoneValue.size()){
            return 0;
        }
        if(dp[index] != INT_MIN)
        return dp[index];
        int take1 = stoneValue[index] - solve(index+1,stoneValue,dp);
        int ans = take1;
        
        if(index+1 < stoneValue.size()){
        int take2 = stoneValue[index]+stoneValue[index+1] - solve(index+2,
        stoneValue,dp);
        ans = max(ans,take2);
        }
        if(index+2 < stoneValue.size()){
        int take3 = stoneValue[index]+stoneValue[index+1]+stoneValue[index+2] - solve(index+3,stoneValue,dp);
        ans = max(ans,take3);
        }
        dp[index] = ans;
        return dp[index];
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(stoneValue.size(),INT_MIN);
        int check = solve(0,stoneValue,dp);
        if(check > 0) return "Alice";
        if(check == 0) return "Tie";
        return "Bob";
    }
};