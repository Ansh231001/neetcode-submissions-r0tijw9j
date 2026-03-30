class Solution {
public:

    void dfs(const vector<int>& nums, int itr, vector<int>& subset, vector<vector<int>>& res){
        if(itr >= nums.size()){
            res.push_back(subset);
            return;
        }

        subset.push_back(nums[itr]);
        dfs(nums, itr+1, subset, res);
        subset.pop_back();
        dfs(nums, itr+1, subset, res);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;
        vector<vector<int>> res;
        dfs(nums, 0, subset, res);

        return res;
    }
};
