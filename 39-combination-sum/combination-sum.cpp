class Solution {
public:
    void combination (int index , vector<vector<int>>& answer , vector<int>& candidates, vector<int>&temp , int target){
        if(index == candidates.size()){
            if(target == 0){
                answer.push_back(temp);
            }
            return;
        }
        if(candidates[index]<=target){
            temp.push_back(candidates[index]);
            combination(index , answer , candidates , temp , target-candidates[index]);
            temp.pop_back();
        }
        combination(index + 1 , answer , candidates , temp , target);
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> answer;
        vector<int> temp;
        combination(0 , answer , candidates , temp , target);
        return answer;
    }
};