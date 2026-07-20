class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();// i 
        int n = grid[0].size(); // j
        while(k>0){
            vector<vector<int>> temp = grid;
            for(int i=0 ;i<m;i++){
                for(int j=0;j<n;j++){
                    if(i==m-1 && j==n-1){
                        temp[0][0] = grid[i][j];
                    }
                    else if(j==n-1) {
                        temp[i+1][0]=grid[i][j];
                    }
                    else temp[i][j+1] = grid[i][j];
                }
            }
            grid = temp;
            k--;
        }
        return grid;
    }
};