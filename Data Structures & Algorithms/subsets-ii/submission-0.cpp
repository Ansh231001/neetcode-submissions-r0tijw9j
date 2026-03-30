class Solution {
public:

    void dfs(vector<int>& nums, int itr, vector<int>& temp, vector<vector<int>>& ans, set<vector<int>>& s){
        
        if(itr > nums.size() - 1){
            if(s.find(temp) != s.end())
                return;
            else {
                s.insert(temp);
                ans.push_back(temp);
                return;
            }
        }

        temp.push_back(nums[itr]);
        dfs(nums, itr+1, temp, ans, s);

        temp.pop_back();
        dfs(nums, itr+1, temp, ans, s);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> s;
        vector<vector<int>> ans;
        vector<int> temp;

        sort(nums.begin(), nums.end());

        dfs(nums, 0, temp, ans, s);

        return ans;
    }
};