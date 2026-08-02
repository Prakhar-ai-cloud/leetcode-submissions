class Solution {
public:
    void solve(int index1, vector<string>& answer , string& temp, string& digits, unordered_map<int,vector<char>>& map){
        if(index1 == digits.size()){
            if(temp.size()==digits.size()){
                answer.push_back(temp);
            }
            return;
        }
        int charc = digits[index1]-'0';
        vector<char> copy = map[charc];
        for(int i=0;i<copy.size();i++){
            //take first element;
            temp += copy[i];
            solve(index1 +1 , answer, temp , digits,map);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<int,vector<char>> map;
        map[2] = {'a','b','c'};
        map[3] = {'d','e','f'};
        map[4] = {'g','h','i'};
        map[5] = {'j','k','l'};
        map[6] = {'m','n','o'};
        map[7] = {'p','q','r','s'};
        map[8] = {'t','u','v'};
        map[9] = {'w','x','y','z'};
        string temp;
        vector<string> answer;
        solve(0,answer,temp,digits,map);
        return answer;

    }
};