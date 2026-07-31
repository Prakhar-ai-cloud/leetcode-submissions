class Solution {
public:

    void combination(int index , int k, vector<vector<int>>& result, vector<int>& array , vector<int>& temp){
     
        if(temp.size()==k){
            result.push_back(temp);
            return;
        }
           if(index == array.size()){
            return;
        }
        temp.push_back(array[index]);
        combination(index+1,k,result,array,temp);
        temp.pop_back();
        combination(index+1,k,result,array,temp);      
        
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> array(n,0);
            for(int i=0;i<n;i++){
                array[i]=i+1;
            }
        vector<int> temp;
        vector<vector<int>> result;
        combination(0,k,result,array,temp);
        sort(result.begin(),result.end());
        return result;
    }
};