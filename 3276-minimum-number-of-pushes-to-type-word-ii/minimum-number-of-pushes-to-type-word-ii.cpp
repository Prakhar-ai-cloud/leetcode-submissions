class Solution {
public:
    int minimumPushes(string word) {
     int n = word.size();
     unordered_map<char,int> freq;
     for(int i=0;i<n;i++){
        freq[word[i]]++;
     }
     vector<pair<int,char>> frequency;
     for(auto &it:freq){
        frequency.push_back({it.second,it.first});
     }
        sort(frequency.begin(),frequency.end(),greater<pair<int,char>>());
        int count = 0;
        for(int i=0 ; i<frequency.size();i++){
            
            count+= (1+i/8)*frequency[i].first;
        }
        return count;
    }
};