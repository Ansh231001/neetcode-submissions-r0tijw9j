class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_set<string> seen;        // to avoid duplicate triplets
        vector<vector<int>> ans;

        for (int i = 0; i < nums.size(); i++) {

            unordered_map<int, int> map;   // reset map for each i
            int target = -nums[i];

            // build frequency map for elements after i
            for (int j = i + 1; j < nums.size(); j++) {
                map[nums[j]]++;
            }

            for (int j = i + 1; j < nums.size(); j++) {
                int need = target - nums[j];

                // reduce count of current element before checking
                map[nums[j]]--;

                if (map[need] > 0) {
                    vector<int> vec = {nums[i], nums[j], need};
                    sort(vec.begin(), vec.end());
                    
                    string key = to_string(vec[0]) + "," +
                                 to_string(vec[1]) + "," +
                                 to_string(vec[2]);

                    if (seen.count(key) == 0) {
                        ans.push_back(vec);
                        seen.insert(key);
                    }
                }
            }
        }
        return ans;
    }
};
