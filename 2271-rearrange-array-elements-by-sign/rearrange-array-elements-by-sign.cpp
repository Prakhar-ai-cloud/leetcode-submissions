class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> odd;
        vector<int> even;
        for(int i=0;i<n;i++){
            if(nums[i]>0) odd.push_back(nums[i]);
            else even.push_back(nums[i]);
        }
        vector<int>answer;
        for(int i=0;i<odd.size();i++){
            answer.push_back(odd[i]);
            answer.push_back(even[i]);
        }
        return answer;
    }
};