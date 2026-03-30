class Solution {
public:

    bool valid(string s){
    stack<char> st;
    for(char x : s){
        if(x == '(')
            st.push(x);
        else {
            if(st.empty())
                return false;
            st.pop();
        }
    }

    return st.empty();
}

    void dfs(int cn, int n, int c1, int c2, vector<string>& ans, string& s){
        if(cn == 0){
            if(valid(s))
                ans.push_back(s);
            return;
        }

        if(c1 > n)
            return;
        
        if (c2 > c1)
            return;
        
        s += '(';
        dfs(cn-1, n, c1+1, c2, ans, s);
        s.pop_back();
        s += ')';
        dfs(cn-1, n, c1, c2+1, ans, s);
        s.pop_back();
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s = "";

        dfs(2*n, n, 0, 0, ans, s);

        return ans;
    }
};
