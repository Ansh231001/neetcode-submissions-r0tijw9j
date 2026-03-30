class Solution {
public:

    void dfs(int cur_sum, int sum, int itr, vector<int>& temp, vector<int>& nums, vector<vector<int>>& ans){
        if(cur_sum == sum){
            ans.push_back(temp);
            return;
        }
        if(cur_sum > sum or itr > nums.size() - 1)
            return;
        

        temp.push_back(nums[itr]);
        dfs(cur_sum + nums[itr], sum, itr+1, temp, nums, ans);
        temp.pop_back();
        while (itr + 1 < nums.size() && nums[itr] == nums[itr + 1]) 
            itr++;
        
        dfs(cur_sum, sum, itr+1, temp, nums, ans);
    }

    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        dfs(0, target, 0, temp, nums, ans);

        return ans;
    }
};
