class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<vector<int>> st;
        int n = temperatures.size();
        vector<int> answer(n,0);
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&st.top()[0]<=temperatures[i]) st.pop();
            if(!st.empty()){
                answer[i] = st.top()[1]-i;
            }
            st.push({temperatures[i],i});
        }
        return answer;
    }
};
