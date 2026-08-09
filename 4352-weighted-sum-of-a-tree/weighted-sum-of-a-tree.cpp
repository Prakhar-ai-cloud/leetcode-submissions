class Solution {
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n = parent.size();
        vector<vector<int>> adjL(n);
        int root;
        for(int i=0;i<n;i++){
            if(parent[i]==-1) {
                root = i;
                continue;
            }
            else{
                adjL[parent[i]].push_back(i);
            }
        }
        int height = 1;
        queue<int> q;
        q.push(root);
        vector<int> depth(n);
        while(!q.empty()){
            int num = q.size();
            for(int i=0;i<num;i++){
                int node = q.front();
                q.pop();
                depth[node] = height;
                for(auto& it:adjL[node]){
                    q.push(it);
                }
            }
            height++;
        }
        height--;
        long long sum = 0;
        for(int i=0;i<depth.size();i++){
            sum += 1LL*nums[i]*(height - depth[i]+1);
        }
        return sum;
    }
};