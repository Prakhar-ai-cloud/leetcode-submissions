class Solution {
public:

    void combination (int index , vector<vector<int>>& answer , vector<int>& candidates, vector<int>&temp , int target){
        if(index == candidates.size()){
            if(target == 0){
                sort(temp.begin(),temp.end());
                answer.push_back(temp);
            }
            return;
        }
        if(candidates[index]<=target){
            temp.push_back(candidates[index]);
            combination(index + 1, answer , candidates , temp , target-candidates[index]);
            temp.pop_back();
        }
        while(index + 1 < candidates.size() &&
      candidates[index] == candidates[index+1])
{
    index++;
}
        combination(index + 1 , answer , candidates , temp , target);
        return;
    }


    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> answer;
        vector<int> temp;
        sort(candidates.begin(),candidates.end());
        combination(0 , answer , candidates , temp , target);
        sort(answer.begin(),answer.end());
        answer.erase(unique(answer.begin(), answer.end()), answer.end());
        return answer;
    }
};