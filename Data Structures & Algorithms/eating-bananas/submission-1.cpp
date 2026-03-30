class Solution {
public:
    
    long long int helper(int rate, vector<int> piles)
    {
        long long int hours = 0;
        for(int i = 0; i < piles.size(); i++)
        {
            hours += (piles[i] / rate); 
            if(piles[i] % rate != 0)
                hours++;
        }
            
        return hours;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = INT_MIN;
        for(int x : piles)
            maxi = max(maxi , x);
        
        long long int s = 1;
        long long int e = maxi;
        long long int res = e;
        while(s <= e)
        {
            long long int mid = (s+e)/2;
            long long int hours = helper(mid , piles);
            if(hours <= h)
            {
                res = min(res , mid);
                e = mid - 1;
            }
            else
                s = mid + 1;
        }
        return res;
    }
};