class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string compare = strs[0];
        
        for(int i=1;i<n;i++){
            string ans;
            string temp = strs[i];
            int it1 = 0;
            int it2 = 0;
            while(it1 < compare.size() && it2 < temp.size()){
                if(compare[it1] == temp[it2]){
                    ans += compare[it1];
                    it1++;
                    it2++;
                }
                else{
                    break;
                }
            }
            compare = ans;
        }
        return compare;
    }
};