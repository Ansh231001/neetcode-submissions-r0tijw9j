class Solution {
public:
    int findMin(vector<int> &nums) {
        int mini = INT_MAX;
        int s = 0;
        int e = nums.size()-1;
        while(s <= e){
            if(nums[s] < nums[e]){
                mini = min(mini, nums[s]);
                break;
            }
            int mid = (s+e)/2;
            mini = min(nums[mid], mini);
            if(nums[mid] >= nums[s])
                s = mid + 1;
            else
                e = mid - 1;
        }   
        return mini;
    }
};
