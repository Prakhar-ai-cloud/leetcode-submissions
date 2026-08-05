class Solution {
public:
    void dfs(int index, vector<int>& visited, vector<vector<int>>& adjL, vector<int>& bugged){
        if(visited[index]!=-1){
            return;
        }
        visited[index] = 1;
        bugged.push_back(index);
        for(auto& it: adjL[index]){
            dfs(it,visited,adjL,bugged);          
        }

    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adjL(n);
        for(auto& it:invocations){
            int u = it[0];
            int v = it[1];
            adjL[u].push_back(v);
        }
        vector<int> visited(n,-1);
        vector<int> bugged;
        dfs(k,visited,adjL,bugged);
        //now bugged has all the suspicious nodes. now we will check from remaining nodes whether we find any element invoked by bug and push it in answer;

        vector<int>temp;
        for(int i=0;i<n;i++){
            if(visited[i] == -1) temp.push_back(i);
        }
        unordered_set<int> bugset;
        for(int i=0;i<bugged.size();i++) bugset.insert(bugged[i]);
        for(int i=0;i<temp.size();i++){
            int node = temp[i];
            for(auto&it : adjL[node]){
                if(bugset.find(it)!=bugset.end()){
                    vector<int> answer;
                    for(int i=0;i<n;i++) answer.push_back(i);
                    return answer;
                }
            }
        }
        return temp;


    }
};