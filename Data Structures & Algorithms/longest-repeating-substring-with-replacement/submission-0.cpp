class Solution {
public:
/*
"In simple words, we calculate the number
of characters that need replacement by taking the total 
window size and subtracting the count of the most frequent characte
(since we would want to convert all other characters into this most frequent one). 
As long as this replacement count is <= k, the window is valid."
when we are shrinking the window, 
we are not recomputing the max frequency so technically, 
we are not storing the current window's maximum frequency but the overall 
max freq encountered until now. The code still works because, if the frequency is lower, 
it never updates the maximum length so there would never be the overwriting of
max length in that case. I am trying to break it somehow using this condition
 but I can't think of any case like that. But correct 
practice would be to recompute the maximum frequency to 
calculate the correct maximum frequency in our current window.
*/
    int characterReplacement(string s, int k) {
        unordered_map<char, int> map;
        int j = 0, maxFreq = 0; 
        int ans = 0;

        for(int i = 0; i < s.length(); i++){
            map[s[i]]++;
            maxFreq = max(maxFreq, map[s[i]]);
            while((i - j + 1) - maxFreq > k){
                map[s[j]]--;
                j++;
            }

            ans = max(ans, i-j+1);
        }

        return ans;
    }
};
