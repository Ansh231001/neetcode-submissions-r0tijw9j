class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size()-1;
        vector<int> ans;
        while(s < e){
            int sum = nums[s] + nums[e];
            if(sum == target){
                ans.push_back(s+1);
                ans.push_back(e+1);
                break;
            }
            else if(sum < target)
                s++;
            else
                e--;

        }

        return ans;
    }
};
