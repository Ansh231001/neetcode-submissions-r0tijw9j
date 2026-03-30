class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for(int x: nums){
            map[x]++;
        }
        priority_queue<pair<int, int>> pq;
        for(auto itr : map){
            pq.push(make_pair(itr.second, itr.first));
        }

        vector<int> ans;
        for(int i = 0; i < k; i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;

    }
};
