class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int min_ind = -1;
        int max_ind = -1;
        int curr_max = INT_MIN;
        int curr_min = INT_MAX;
        for(int i=0;i<n ; i++){
            if(nums[i] > curr_max){
                curr_max = nums[i];
                max_ind = i;
            }
            if(nums[i]<curr_min){
                curr_min = nums[i];
                min_ind = i;
            }
        }
        // no we have left and right.
        int mini = min(max_ind,min_ind);
        int maxi = max(max_ind,min_ind);
        //base case;
        int ans = mini + 1 + n - maxi;

        // another case remove maxi from front;
        ans = min(ans , maxi+1);
        ans = min(ans , n-mini);
        return ans;
    }
};