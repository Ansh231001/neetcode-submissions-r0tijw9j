class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0)
            return 0;
        if(s.length() == 1)
            return 1;
        
        int ans = 1;
        set<char> map;
        
        for(int i = 0; i < s.length(); i++){
            int j = i;
            while(j < s.length()){
                if(map.find(s[j]) != map.end())
                    break;
                else
                    map.insert(s[j]);
                j++;
            }
            ans = max(j - i, ans);
            map.clear();
        }

        return ans;

    }
};
