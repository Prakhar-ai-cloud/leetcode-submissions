class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans;
        map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        while(!mp.empty()){
            vector<int> erase;
            for(auto& it: mp){
                    ans.push_back(it.first);
                    it.second--;
                    if(it.second == 0) erase.push_back(it.first);
            }
            for(auto&it1:erase) mp.erase(it1);
        }
        return ans;
    }
};