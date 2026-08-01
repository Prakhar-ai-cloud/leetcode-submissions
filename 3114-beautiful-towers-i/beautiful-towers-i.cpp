class Solution {
public:
    long long maximumSumOfHeights(vector<int>& heights) {
        int n = heights.size();

        long long answer = 0;

        for (int j = 0; j < n; j++) {

            long long sum = heights[j];

            int current_min = heights[j];

            // Traverse right
            for (int i = j + 1; i < n; i++) {
                current_min = min(current_min, heights[i]);
                sum += current_min;
            }

            // Traverse left
            current_min = heights[j];

            for (int i = j - 1; i >= 0; i--) {
                current_min = min(current_min, heights[i]);
                sum += current_min;
            }

            answer = max(answer, sum);
        }

        return answer;
    }
};