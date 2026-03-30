class Solution {
public:
    int maxArea(vector<int>& heights) {
        int ans = -1;
        int s = 0;
        int e = heights.size() - 1;

        while(s < e){
            int temp = min(heights[s], heights[e]) * (e - s);
            ans = max(temp, ans);

            if(heights[s] <= heights[e])
                s++;
            else
                e--;
        }

        return ans;
    }
};
