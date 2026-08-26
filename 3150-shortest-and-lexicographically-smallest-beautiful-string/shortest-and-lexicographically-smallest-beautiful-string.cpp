class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        vector<string> ans;
        int left = 0;
        int right = 0;
        int count = 0;
        int minl = INT_MAX;
        while(right<n){
            if(s[right]=='1') count++;
            while(count == k){
            minl = min(minl,right-left+1);
            if(s[left]=='1') ans.push_back(s.substr(left,right-left+1));
            if(s[left]=='1'){
                count --;
            }
            left ++;

            }
            right++;
        }
        for(auto& it: ans) cout << it << " ";
        vector<string> finalans;
        for(int i=0;i<ans.size();i++){
            if(ans[i].size()==minl) finalans.push_back(ans[i]);
        }
        if(finalans.size()==0) return "";
        sort(finalans.begin(),finalans.end());
        return finalans[0];
    }
};