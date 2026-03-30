class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;

        for(int i = 0; i < prices.size(); i++){
            int j = i + 1;
            while(prices[i] < prices[j] and j < prices.size()){
                ans = max(ans, prices[j] - prices[i]);
                j++;
            }
        }

        return ans;
    }
};
