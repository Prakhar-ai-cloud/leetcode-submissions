class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;
        vector<int> result;
        for(int i=0;i<nums.size();i++){
            int need = target-nums[i];
            if(map.count(need)){
                result.push_back(map[need]);
                result.push_back(i);
                return result;
            }
            map.insert({nums[i],i});
        }
        return result;
    }
};