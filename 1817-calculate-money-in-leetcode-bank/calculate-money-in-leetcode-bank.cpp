class Solution {
public:
    int totalMoney(int n) {
        // 28 in first week, then 7+ for everyweek
        // do n/7 for complete weeks.
        int days = n%7;
        int weeks = n/7;
        int answer = 0;
        int it = 28;
        for(int i=0;i<weeks;i++){
            answer += it;
            it+=7;
        }
        for(int i = 0 ; i< days;i++){
            answer += weeks + 1 + i;
        }
        return answer;
        
    }
};