class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        sort(intervals.begin(),intervals.end());
        int left = 0;
        int right = 1;
        while(right < intervals.size()){
            if(intervals[right][0]<=intervals[left][1]){
                intervals[right][0]=intervals[left][0];
                intervals[right][1]=max(intervals[right][1],intervals[left][1]);
                left++;
                right++;
            }
            else{
                result.push_back(intervals[left]);
                left++;
                right++;
            }
        
        }   
        result.push_back(intervals[left]);
        return result;     
    }
};