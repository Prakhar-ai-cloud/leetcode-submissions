class Solution {
public:
    void solve(string& ans, int open, int close, vector<string>& answer){
        if(open == 0 && close == 0){
            answer.push_back(ans);
            return;
        }
        if(open > 0){
            ans += '(';
            solve(ans,open-1,close,answer);
            ans.pop_back();
        }
        if(close > open){
            ans += ')';
            solve(ans,open,close-1,answer);
            ans.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string ans = "";
        vector<string> answer;
        solve(ans,n,n,answer);
        return answer;
    }
};