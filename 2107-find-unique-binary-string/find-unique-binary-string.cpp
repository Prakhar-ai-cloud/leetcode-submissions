class Solution {
public:
    void backtrack(int count, unordered_set<string>& numsSet, string& temp, string& answer){
        if(count == numsSet.size()){
            if(temp.size()==numsSet.size()&&numsSet.find(temp) == numsSet.end()){
                answer = temp;
                return;
            }
            return;
        }

        // take 0;
        temp += '0';
       
        backtrack(count+1,numsSet,temp,answer);
        temp.pop_back();
        temp+='1';
        backtrack(count+1,numsSet,temp,answer);
        temp.pop_back();

    }
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        unordered_set<string> numsSet;
        for(int i=0;i<n;i++){
            numsSet.insert(nums[i]);
        }
        string temp;
        string answer;
        backtrack(0,numsSet,temp,answer);
        return answer;
    }
};