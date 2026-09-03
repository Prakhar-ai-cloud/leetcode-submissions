class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        int even_count = 0;
        int odd_count = 0;
        int min_even = INT_MAX;
        int min_odd = INT_MAX;

        for(int i=0;i<n;i++){
            if(nums1[i]%2 == 0){
                even_count++;
                if(nums1[i]<min_even) min_even = nums1[i];
            }
            else{
                odd_count++;
                if(nums1[i]<min_odd) min_odd = nums1[i];
            }
        }
        if(odd_count == 0 || even_count == 0) return true;

        // observation: an array with odd numbers can never be converted in an even array.
        // only check to convert array to odd array;
        bool check = true;
        for(int i=0;i<n;i++){
            if(nums1[i]%2 == 0){
                if(nums1[i] - min_odd < 1){
                    check = false;
                    break;
                }
            }
        }
        return check;
    }
};