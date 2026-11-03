class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n=s.size();
        if(n==1)return false;
        if(n==0)return true;
        int it=0;
        while(it<n){
           if(s[it]=='['||s[it]=='{'||s[it]=='('){
                st.push(s[it]);
                it++;
            }
            else{
                if (st.empty()) return false;
                if((s[it]==']'&&st.top()=='[')||(s[it]=='}'&&st.top()=='{')||(s[it]==')'&&st.top()=='(')){
                    it++;
                    st.pop();
                    continue;
                }
                else return false;
            } 
        }
        return st.empty();
    }
};