class Solution {
public:
    int minimumPushes(string word) {
        int distinct = word.size();
        int count = 0;
        if(distinct <= 8){
            count += distinct;
        }
        else if(distinct <=16 && distinct > 8){
            int extra = distinct - 8;
            count += 2*extra;
            count += 8;
        }
        else if(distinct <= 24 && distinct > 16){
            int extra = distinct - 16;
            count += 3*extra;
            count += 24;
        }
        else{
            int extra = distinct - 24;
            count += 4*extra;
            count+= 48;
        }
        return count;
    }
};