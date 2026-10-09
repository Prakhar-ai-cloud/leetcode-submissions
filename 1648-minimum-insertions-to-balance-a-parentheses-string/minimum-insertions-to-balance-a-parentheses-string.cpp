class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        int closed_count = 0;
        int answer = 0;
        for(int i=n-1;i>=0;i--){
            if(s[i] == ')') closed_count++;
            else{
                if(closed_count%2 == 1){
                    answer ++;
                    closed_count--;
                }
                else if(closed_count >= 2){
                    closed_count-=2;
                }
                else{
                    answer += 2 - closed_count;
                    closed_count = 0;
                } 
            }
        }
        if(closed_count%2 == 0) answer += closed_count/2;
        else answer += 1 + (closed_count+1)/2;
        return answer;
    }
};