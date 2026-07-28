class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int ans = 0;
    int n = colors.size();
// Fix first color
for(int i = colors.size() - 1; i >= 0; i--){
    if(colors[i] != colors[0]){
        ans = i;
        break;
    }
}

// Fix last color
for(int i = 0; i < colors.size(); i++){
    if(colors[i] != colors.back()){
        ans = max(ans, n - 1 - i);
        break;
    }
}

return ans;
    }
};