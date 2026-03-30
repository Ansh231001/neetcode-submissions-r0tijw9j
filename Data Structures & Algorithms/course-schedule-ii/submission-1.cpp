class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& nums) {
        map<int, vector<int>> edges;
        vector<int> indegree(numCourses, 0);

        
        for(int i = 0; i < nums.size(); i++){
            edges[nums[i][1]].push_back(nums[i][0]);
            indegree[nums[i][0]]++;    
        }

        queue<int> q;
        for(int i = 0; i < indegree.size(); i++){
            if(indegree[i] == 0)
                q.push(i);
        }

        if(q.empty())
            return {};

        vector<int> res;

        while(!q.empty()){
            auto temp = q.front();
            q.pop();

            res.push_back(temp);
            for(auto itr : edges[temp]){
                indegree[itr]--;
                if(indegree[itr] == 0)
                    q.push(itr);
            }
        }


        if(res.size() != numCourses)
            return {};
            
        return res;
    }
};
