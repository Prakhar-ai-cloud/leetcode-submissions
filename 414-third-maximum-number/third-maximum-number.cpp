class Solution {
public:
    int thirdMax(vector<int>& nums) {
        unordered_set<int> st;
        int maximum = INT_MIN;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
            maximum = max(nums[i],maximum);
        }
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto &i : st){
            pq.push(i);
            if(pq.size()>3) pq.pop();
        }
        if(pq.size()==3) return pq.top();
        return maximum;
    }
};