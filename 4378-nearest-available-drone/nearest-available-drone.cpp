class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int minimum = INT_MAX;
        int min_index = -1;
        for(int i=0 ; i<drones.size();i++){
            int x1 = drones[i][0];
            int y1 = drones[i][1];
            int range = drones[i][2];
            int x2 = target[0];
            int y2 = target[1];
            int distance = abs(x1-x2) + abs(y1-y2);
            if(distance <= range){
            if(distance < minimum){
                minimum = distance;
                min_index = i;
            }
            }
        }
        return min_index;
    }
};