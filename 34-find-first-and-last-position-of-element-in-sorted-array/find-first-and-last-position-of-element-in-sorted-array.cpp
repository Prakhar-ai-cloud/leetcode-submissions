class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n-1;
        int lower = -1;
        int higher = -1;
        while(left<=right){
            int mid = left+(right-left)/2;
            if(nums[mid] == target){
                higher = mid;
                left = mid+1;
            
            }
            else if(nums[mid] > target) right = mid-1;
            else left = mid+1;

        }
        left = 0;
        right = n-1;
        while(left<=right){
            int mid = left+(right-left)/2;
            if(nums[mid] == target){
                lower = mid;
                right = mid-1;;            
            }
            else if(nums[mid] > target) right = mid-1;
            else left = mid+1;

        }
        return {lower,higher};
    }
};