class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int it1 = 0;
        int it2 = 0;
        int count = 0;
        while(it1 < g.size() && it2 < s.size()){
            if(g[it1]<= s[it2]){
                it1++;
                it2++;
                count++;
            }
            else it2++;
        }
        return count;
    }
};