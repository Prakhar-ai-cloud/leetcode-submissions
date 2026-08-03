class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int counter = 0;
        int answer = INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1) counter++;
            else{
                answer = max(answer,counter);
                counter = 0;
            }
        }
        answer = max(answer,counter);
        return answer;
    }
};