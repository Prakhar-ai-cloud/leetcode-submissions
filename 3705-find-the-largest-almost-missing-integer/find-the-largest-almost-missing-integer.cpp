class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        int right = k;
        unordered_map<int,int> mp;
        if(k==n){
            return *max_element(nums.begin(),nums.end());
        }
        while(right<=n){
            for(int i=left ; i<right ; i++){
                mp[nums[i]]++;
            }
            left++;
            right++;
        }
        int ans = -1;
        for(auto&it:mp){
            if(it.second == 1) ans = max(ans,it.first);
        }
        return ans;
    }
};