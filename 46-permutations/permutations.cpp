class Solution {
public:
    void solve(int index, vector<int>& nums, vector<int>& temp, vector<vector<int>>&answers, vector<int>& visited){
        if(index == nums.size()){
            if(temp.size()==nums.size()){
                answers.push_back(temp);
            }
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(visited[nums[i]+10]) continue;
            visited[nums[i]+10] = 1;
            temp.push_back(nums[i]); // take condition;
            solve(index+1, nums, temp, answers,visited);
            visited[nums[i]+10] = 0;
            temp.pop_back();
        }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();  
       vector<int> visited(21,0);
       vector<int> temp;
       vector<vector<int>> answers;
       solve(0, nums, temp, answers,visited);
       return answers;
    }
};