class Solution {
public:
    long long numways(int target,vector<int>& nums, vector<long long>& dp){
        if(target==0) return 1;
        if(dp[target]!=-1) return dp[target];
        long long ways=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=target){
                ways += numways(target-nums[i],nums,dp);
            }
        }
        dp[target] = ways;
        return dp[target];
    }
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<long long> dp(target+1,-1);
        return numways(target,nums,dp);
    }
};