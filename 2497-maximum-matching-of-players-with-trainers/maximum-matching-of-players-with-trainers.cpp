class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        int it1 = 0;
        int it2 = 0 ;
        int count = 0;
        while(it1 < players.size() && it2 < trainers.size()){
            if(players[it1]<=trainers[it2]){
                it1++;
                it2++;
                count++;
            }
            else it2++;
        }
        return count;
    }
};