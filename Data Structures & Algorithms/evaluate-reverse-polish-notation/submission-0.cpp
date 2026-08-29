class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(int i=0;i<tokens.size();i++) {
            if(tokens[i]=="+"||tokens[i]=="/"||tokens[i]=="-"||tokens[i]=="*") {
                int r=st.top();
                st.pop();
                int s=st.top();
                st.pop();
                if(tokens[i]=="+") st.push(r+s);
                else if(tokens[i]=="-") st.push(s-r);
                else if(tokens[i]=="*") st.push(r*s);
                else st.push(s/r); 
            }
            else st.push(stoi(tokens[i]));
        }
        return st.top();
    }
};
