class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int it = 0;
        while(it<tokens.size()){
            if(tokens[it]!="+"&&tokens[it]!="-"&&tokens[it]!="/"&&tokens[it]!="*"){
                st.push(stoi(tokens[it]));
            }
            else{
                char temp = tokens[it][0];
                switch(temp){
                    case '+':{
                    int a = st.top();
                    st.pop();
                    int b = st.top();
                    st.pop();
                    st.push(a+b);
                    break;
                    }
                    case '-':{
                    int c = st.top();
                    st.pop();
                    int d = st.top();
                    st.pop();
                    st.push(d-c);
                    break;
                    }
                    case '*':{
                    int e = st.top();
                    st.pop();
                    int f = st.top();
                    st.pop();
                    st.push(e*f);
                    break;
                    }
                    case '/':{
                    int g = st.top();
                    st.pop();
                    int h = st.top();
                    st.pop();
                    st.push(h/g);
                    break;
                    }
                }
            }
            it++;
        }
        return st.top();
    }
};
