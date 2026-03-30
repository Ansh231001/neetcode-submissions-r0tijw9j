class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> nums(cost.size(), 0);

        nums[0] = cost[0];

        if(cost.size() > 1)
            nums[1] = cost[1];

        for(int i = 2; i < nums.size(); i++){
            nums[i] = cost[i] + min(nums[i-1], nums[i-2]);
        }

        return min(nums[nums.size()-1], nums[nums.size()-2]);
    }
};
