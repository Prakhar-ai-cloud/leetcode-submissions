class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        if(n%2==1) return {};

        unordered_map<int,int> map;
        for(int i = 0;i<n;i++){
            map[changed[i]]++;
        }
        sort(changed.begin(),changed.end());
        vector<int> answer;
        for(int i=0;i<n;i++){
            if(map[changed[i]]==0) continue;
            if(map.find(2*changed[i])!=map.end()){
                answer.push_back(changed[i]);
                map[changed[i]]--;
                map[2*changed[i]]--;
            }
        }
       for(auto& it: map){
        if(it.second != 0) return {};
       }
       return answer;
    }
};