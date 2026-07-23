class Solution {
public:
    int firstUniqChar(string s) {
        queue<pair<char,int>> q;
        unordered_map<char,int> visited;
        for(int i=0;i<s.size();i++){
            if(q.empty()||!visited[s[i]]) q.push({s[i],i});
            visited[s[i]]++;
        }
        while(!q.empty()){
            char a=q.front().first;
            int index = q.front().second;
            if(visited[a]>1) q.pop();
            else return index;
        }
        return -1;
    }
};