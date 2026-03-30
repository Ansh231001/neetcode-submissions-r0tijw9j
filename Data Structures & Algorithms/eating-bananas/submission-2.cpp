class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long s = 1;   // FIXED
        long long e = *max_element(piles.begin(), piles.end());
        
        long long res = e;

        while(s <= e){
            long long rate = s + (e - s) / 2;   // FIXED
            long long hours = 0;

            for(int x : piles){
                hours += (x + rate - 1) / rate;  // SIMPLIFIED
            }

            if(hours <= h){
                res = rate;
                e = rate - 1;
            }
            else{
                s = rate + 1;
            }
        }
        return res;
    }
};
