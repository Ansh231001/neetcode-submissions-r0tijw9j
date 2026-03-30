class Solution {
public:
    bool isPalindrome(string s) {
        string result = "";
        for (char c : s) {
            if (isalnum(c)) {
                result += c;
            }
        }

        cout << result;

        int st = 0;
        int e = result.length()-1;
        while(st <= e){
            if(tolower(result[st]) != tolower(result[e])){
                return false;
            }
            st++;
            e--;
        }

        return true;
    }
};
