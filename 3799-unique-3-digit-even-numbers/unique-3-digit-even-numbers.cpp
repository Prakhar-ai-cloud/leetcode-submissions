class Solution {
public:
    void permute(int index, vector<int>& digits, int& count,int& answer, int& sum,unordered_map<int, int>& visited) {

        if(count == 3) {
            if(sum % 2 == 0)
                answer++;
            return;
        }

        for(int digit = 0; digit <= 9; digit++) {
            if(visited[digit] == 0){
                continue;
            }
            // First digit cannot be 0
            if(count == 0 && digit == 0){
                continue;
            }
            // Take
            sum = sum * 10 + digit;
            count++;
            visited[digit]--;
            permute(index + 1, digits, count,answer, sum, visited);
            // Backtrack
            visited[digit]++;
            sum /= 10;
            count--;
        }
    }

    int totalNumbers(vector<int>& digits) {
        unordered_map<int, int> visited;
        for(int i = 0; i<digits.size();i++){
            visited[digits[i]]++;
        }
        int count = 0;
        int answer = 0;
        int sum = 0;
        permute(0, digits, count, answer, sum, visited);
        return answer;
    }
};