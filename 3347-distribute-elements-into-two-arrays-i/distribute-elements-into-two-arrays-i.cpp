class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int last_a = nums[0];
        int last_b = nums[1];
        nums[1]*=-1;
        for(int i=2 ; i<nums.size();i++){
            if(last_a>last_b){
                last_a = nums[i];
            }
            else{
                last_b = nums[i];
                nums[i]*=-1;
            }
        }
        int left = 0;
        while(left < nums.size()){
            while(left < nums.size()&& nums[left]>0) left++;
            if(left == nums.size()) break;
            int right = left+1;
            while(right<nums.size()&&nums[right]<0) right++;
            if(right == nums.size()) break;
            for(int i=right ; i>left ; i--){
                swap(nums[i],nums[i-1]);
            }
            left++;

        }
        for(int i=0;i<nums.size();i++){
            nums[i] = abs(nums[i]);
        }
        return nums;
    }
};