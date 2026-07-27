class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int, vector<int> , greater<int>> pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
            if(pq.size()>2)pq.pop();
        }
        int ans = 1;
        for(int i=0;i<2;i++){
            ans*= (pq.top()-1);
            pq.pop();
        }
        return ans;
    }
};