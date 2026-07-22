class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0;
        while(left<nums.size()){

            while(left < nums.size() && nums[left]!=0) left ++;
            if(left == nums.size()) break;
            int right = left+1;
            while(right<nums.size()&&nums[right]==0) right++;
            if (right == nums.size())
            break;
            nums[left] = nums[right];
            nums[right]=0;
            left++;
        }

    }
};