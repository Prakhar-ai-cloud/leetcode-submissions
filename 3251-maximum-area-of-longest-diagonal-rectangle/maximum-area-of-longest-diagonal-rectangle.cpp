class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int max_area= 0;
        int max_diagonal = 0;

        for(int i=0;i<dimensions.size();i++){
            int length = dimensions[i][0];
            int width = dimensions[i][1];
            int diagonal = length*length + width*width;
            int area = length*width;
            if(diagonal > max_diagonal){
                max_diagonal = diagonal;
                max_area = area;
            }
            else if(diagonal == max_diagonal) max_area = max(area,max_area);
        }
        return max_area;
    }
};