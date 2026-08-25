class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }
        for(int i=k ; i<=100 ; i+=k){
            if(st.find(i)==st.end()) return i;
        }

    int a = 100%k;
    return 100 + (k-a);
    }
};