class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> openstack;
        stack<char> closedstack;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') openstack.push(s[i]);
            else{
                if(!openstack.empty()&&s[i]==')'&& openstack.top()=='(') openstack.pop();
                else closedstack.push(s[i]);
            }
        }
        return openstack.size()+closedstack.size();
    }
};