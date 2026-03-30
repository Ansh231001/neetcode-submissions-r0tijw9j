class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& nums) {
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

        int count = 0;

        if(q.empty())
            return false;

        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            count++;
            for(auto itr : edges[temp]){
                indegree[itr]--;
                if(indegree[itr] == 0)
                    q.push(itr);
            }
        }

        return count == numCourses;
    }
};
