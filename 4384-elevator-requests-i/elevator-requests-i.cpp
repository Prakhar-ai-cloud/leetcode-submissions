class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int m = requests.size();
        int current_floor = 0;
        int answer = 0;
        for(int i=0 ; i<m ; i++){
            answer += abs(current_floor - requests[i]);
            current_floor = requests[i];
        }
        return answer;
    }
};