class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prepro(nums.size(),1);
        vector<int> postpro(nums.size(),1);
        prepro[0] = nums[0];
        postpro[nums.size()-1] = nums[nums.size()-1];
        for(int i=1;i<nums.size();i++){
            prepro[i] = nums[i]*prepro[i-1];
        }
        for(int i=nums.size()-2 ; i>=0 ; i--){
            postpro[i] = postpro[i+1]*nums[i];
        }
        vector<int> sol(nums.size(),0);
        sol[0] = postpro[1];
        sol[nums.size()-1] = prepro[nums.size()-2];
        for(int i=1 ; i<nums.size()-1;i++){
            sol[i] = prepro[i-1]*postpro[i+1];
        }
        return sol;
    }
};