class Solution {
public:
    vector<int> primes(int n){
        vector<int> temp;
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                temp.push_back(i);
                while(n%i==0) n/=i;
            }
        }
        if(n>1) temp.push_back(n);
        return temp;
    }
    int longestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> factors;
        for(int i=0;i<n;i++){
            factors.push_back(primes(nums[i]));
        }
        unordered_map<int,int> mp;
        int left = 0;
        int answer = 0;
        for(int i=0;i<n;i++){
            for(auto& it: factors[i]){
                mp[it]++;
            }
            while(mp.size()>k){
                for(auto&ite : factors[left]){
                    mp[ite]--;
                    if(mp[ite]==0) mp.erase(ite);
                }
                left++;
            }
            answer = max(answer,i-left+1);
        }
        return answer;
    }
};