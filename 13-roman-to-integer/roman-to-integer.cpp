class Solution {
public:
    int romanToInt(string s) {
       unordered_map<char,int> map;
       map['I'] = 1;
       map['V'] = 5;
       map['X'] = 10;
       map['L'] = 50;
       map['C'] = 100;
       map['D'] = 500;
       map['M'] = 1000; 
        int n = s.size();
       int answer = 0;
      for(int i=n-1 ; i>0 ; i--){
        if(s[i]=='.') continue;
        if(map[s[i]] <= map[s[i-1]]) answer+= map[s[i]];
        else{
            answer += map[s[i]] - map[s[i-1]];
            s[i] = '.';
            s[i-1] = '.';
        }
      }
        if(s[0]!='.') answer += map[s[0]];
        return answer;
    }
};