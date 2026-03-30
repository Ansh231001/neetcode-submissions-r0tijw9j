class Solution {
public:

    void dfs(vector<int>& nums, vector<bool>& used, vector<int>& temp, vector<vector<int>>& ans){
        if(temp.size() == nums.size()){
            ans.push_back(temp);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            if(used[i]) 
                continue;

            used[i] = true;
            temp.push_back(nums[i]);

            dfs(nums, used, temp, ans);

            temp.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<bool> used(nums.size(), false);

        dfs(nums, used, temp, ans);

        return ans;
    }
};
