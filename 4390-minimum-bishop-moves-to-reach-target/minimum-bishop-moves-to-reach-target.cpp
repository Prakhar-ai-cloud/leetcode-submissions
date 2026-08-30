class Solution {
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        int parity = source[0]+source[1];
        int check = target[0]+target[1];
        if(parity%2 != check%2) return -1;

        // we know the bishop will only take one or two moves.
        // if it lies on the two possible diagonals then ok else 2 moves.
        // for a same diagonal either x+y or abs(x-y) needs to be same
        int ans = 2;
        if(parity == check || source[0]-source[1] == target[0]-target[1]) ans = 1;
        return ans;
    }
};