class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int> xorvalues;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size();j++){
                xorvalues.insert(nums[i]^nums[j]);
            }
        }
        unordered_set<int> uniqueXor;
        for(int i=0;i<nums.size();i++){
            for(auto &it:xorvalues){
                uniqueXor.insert(nums[i]^it);
            }
        }
        return uniqueXor.size();
    }
};