class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length())   
            return false;

        int left = 0;
        unordered_map<char, int> map1;
        for(char c : s1)
            map1[c]++;
        
        unordered_map<char, int> map2;
        for(int right = 0; right < s2.length(); right++){
            map2[s2[right]]++;

            if(map2 == map1)
                return true;

            while(right - left + 1 > s1.length()){
                map2[s2[left]]--;
                if (map2[s2[left]] == 0)
                    map2.erase(s2[left]);
                left++;
                
                if(map2 == map1)
                    return true;
            }
        }

        return false;
    }
};
