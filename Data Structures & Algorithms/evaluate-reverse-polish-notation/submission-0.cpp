class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;

        for (string t : tokens) {
            if (t == "+" || t == "-" || t == "*" || t == "/") {
                int val1 = s.top(); s.pop();
                int val2 = s.top(); s.pop();

                if (t == "+") s.push(val2 + val1);
                else if (t == "-") s.push(val2 - val1);
                else if (t == "*") s.push(val2 * val1);
                else s.push(val2 / val1);
            } else {
                s.push(stoi(t));
            }
        }
        return s.top();
    }
};
