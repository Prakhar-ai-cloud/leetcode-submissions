class Solution {
public:
    string finalString(string s) {
        int n = s.size();
        string answer;
        for(int i=0 ; i<n; i++){
            if(s[i]== 'i' && answer.size()>0) reverse(answer.begin(),answer.end());
            else answer += s[i];
        }
        return answer;
    }
};