class Solution {
public:
    void back(int index, int&n , vector<char>& chr, string& temp, vector<string>& answer){
        if(index == n){
            if(temp.size()==n){
                answer.push_back(temp);
            }
            return;
        }
        for(int i=0;i<chr.size();i++){
            if(!temp.empty()&&temp.back()==chr[i]) continue;
            temp += chr[i];
            back(index+1,n,chr,temp,answer);          
            temp.pop_back();
        }
    }
    string getHappyString(int n, int k) {
        vector<char> chr = {'a','b','c'};
        string temp;
        vector<string> answer;

     
        back(0,n,chr,temp,answer);
        if(k>answer.size()) return "";
        sort(answer.begin(),answer.end());
        return answer[k-1];
    }
};