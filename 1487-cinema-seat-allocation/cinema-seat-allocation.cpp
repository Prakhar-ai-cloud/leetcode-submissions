class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int m = reservedSeats.size();
        int max_count = 2*n;
        unordered_map<int,vector<int>> mp;
        for(auto&it:reservedSeats){
            int row = it[0];
            int col = it[1];
            mp[row].push_back(col);
        }
        for(auto &it:mp){
            vector<int> reserved = it.second;
                bool a=true;
                bool b=true;
                bool c = true;
            for(int i=0;i<reserved.size();i++){
               
                if(a == true && reserved[i]>=2 && reserved[i]<=5){
                    max_count --;
                    a = false; 
                    cout << it.first<< max_count << " ";
                }
                 if(b == true && reserved[i]>=6 && reserved[i]<=9){
                    max_count--;
                    b = false;
                    cout << it.first << max_count << " ";
                }
                 if (reserved[i] >=4 && reserved[i]<=7) c = false;
            }
            if(a == false && b == false && c == true) max_count++;
                    cout << max_count << " ";
        }

    return max_count;
    }
};