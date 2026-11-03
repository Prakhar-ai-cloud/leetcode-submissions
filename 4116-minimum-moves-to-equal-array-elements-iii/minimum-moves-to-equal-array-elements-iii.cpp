class Solution {
public:
    int minMoves(vector<int>& nums) {
        int target = *max_element(nums.begin(),nums.end());
        int answer = 0;
        for(auto&it:nums){
            answer += target-it;
        }
        return answer;
    }
};