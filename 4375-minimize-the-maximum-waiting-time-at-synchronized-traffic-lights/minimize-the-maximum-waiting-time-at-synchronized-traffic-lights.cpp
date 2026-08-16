class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        int n = lights.size();
        int m = arrivalTime.size();
        int max_lights = 0;
        for(int i=0 ; i<n;i++){
            max_lights = max(max_lights,lights[i]);
        }
        int max_P =0;
        for(int i=0;i<arrivalTime.size() ; i++){
            int r = arrivalTime[i]%period;
            if(r>=max_lights) max_P = max(max_P,period-r);
        }
        return max_P;
    }
};