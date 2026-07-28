class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int count_left = 0;
        int count_right = 0;
        int count_spaces = 0;
        for(int i=0;i<moves.size();i++){
            if(moves[i] == '_') count_spaces++;
            else if( moves[i] == 'R') count_right++;
            else count_left++;
        }
        if(count_right == count_left) return count_spaces;
        return (count_spaces + abs(count_right-count_left));
    }
};