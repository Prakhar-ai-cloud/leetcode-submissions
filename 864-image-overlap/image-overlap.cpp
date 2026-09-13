class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int ans=0;
        int n=img1.size();
        unordered_map<int, int> mp;
        vector<pair<int, int>> i1;
        vector<pair<int, int>> i2;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(img1[i][j]==1) i1.push_back({i, j});
                if(img2[i][j]==1) i2.push_back({i, j});
            }
        }
        for(auto& [i, j]:i1)
        {
            for(auto& [ni, nj]:i2)
            {
                int di=ni-i;
                int dj=nj-j;
                int key=di*3000+dj*30;
                mp[key]++;
                ans=max(ans, mp[key]);
            }
        }
        return ans;
    }
};