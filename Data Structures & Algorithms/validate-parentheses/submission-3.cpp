class Solution {
public:
    bool isValid(string s) {
        if(s.length() == 1)
            return false;
        
        stack<int> st;
        for(char x : s){
            if(x == '(' or x == '{' or x == '[')
                st.push(x);
            else {
                if(st.empty()){
                    return false;
                }
                char top = st.top();

                if(x == ')' and top == '(')
                    st.pop();
                
                else if(x == '}' and top == '{')
                    st.pop();

                else if(x == ']' and top == '[')
                    st.pop();
                else
                    return false;
            }
        }

        return st.empty();
    }
};
