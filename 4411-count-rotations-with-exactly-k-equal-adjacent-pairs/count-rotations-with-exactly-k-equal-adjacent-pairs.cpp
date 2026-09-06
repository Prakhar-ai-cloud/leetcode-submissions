class Solution {
public:
    int countRotations(string s, int k) {
        int n = s.size();
        s = s+s;
        int answer = 0;
        for(int i=0;i<n;i++){
            string temp = s.substr(i,n);
            int count = 0;
            for(int i=1;i<n;i++){
                if(temp[i]==temp[i-1]) count++;
            }
            if(count == k) answer++;
        }
        return answer;
    }
};