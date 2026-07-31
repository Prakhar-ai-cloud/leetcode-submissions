class Solution {
public:

    void combine(int index, int n, int k, vector<int>&temp , vector<vector<int>>& result,vector<int>& array){

        if(temp.size()==k && n==0){
            result.push_back(temp);
            return;
        }
        if(index == array.size()) return;

        if(array[index]<=n){
            temp.push_back(array[index]);
            combine(index+1,n-array[index],k,temp,result,array);
            temp.pop_back();
        }
            combine(index+1,n,k,temp,result,array);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> array = {1,2,3,4,5,6,7,8,9};
        vector<vector<int>> result;
        vector<int> temp;
        combine(0,n,k,temp,result,array);
        return result;
    }
};