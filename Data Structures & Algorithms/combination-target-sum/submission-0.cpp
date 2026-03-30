class Solution {
public:

    void dfs(map<vector<int>, int>& mp, int cur_sum, int sum, vector<int>& nums, vector<int>& temp, vector<vector<int>>& ans){
        if(cur_sum > sum)
            return;

        if(cur_sum == sum){
            vector<int> t = temp;
            sort(t.begin(), t.end());

            if(mp[t])
                return;
            else{
                mp[t]++;
                ans.push_back(t);
                return;
            }
        }

        for(int i = 0; i < nums.size(); i++){
            temp.push_back(nums[i]);
            dfs(mp, cur_sum + nums[i], sum, nums, temp, ans);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        map<vector<int>, int> mp;
        vector<int> temp;

        dfs(mp, 0, target, nums, temp, ans);

        return ans;
    }
};