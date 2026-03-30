class Solution {
public:
/*
    create set or hashmap. agar element + 1 is in set 
    length badhate raho else terminate
*/

    int longestConsecutive(vector<int>& nums) {
        set<int> s;
        int longest = 0;
        for(int x : nums){
            s.insert(x);
        }

        for(int x : nums){
            if(s.find(x-1) == s.end()){
                int length = 0;
                while(s.find(x+length) != s.end()){
                    length++;
                }
                longest = max(longest, length);
            }
        }

        return longest;
    }
};
