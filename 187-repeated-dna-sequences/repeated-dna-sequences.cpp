class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        int left = 0;
        int right = 9;
        unordered_map<string,int> mp;
        while(right<n){
            mp[s.substr(left,10)]++;
            left++;
            right++;
        }
        vector<string> answer;
        for(auto&it : mp){
            if(it.second > 1) answer.push_back(it.first);
        }
        return answer;
    }
};