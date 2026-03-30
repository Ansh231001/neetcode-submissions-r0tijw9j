class Solution {
public:

    set<pair<int, int>> pac;
    set<pair<int, int>> atl;
    vector<int> dir = {-1, 0, 1, 0, -1};

    void dfs(pair<int, int> p, vector<vector<int>>& heights, set<pair<int, int>>& vis, int prevHeight){
        if(p.first < 0 or p.second < 0 
        or p.first >= heights.size() or p.second >= heights[0].size()
        or vis.find(p) != vis.end() or heights[p.first][p.second] < prevHeight) 
            return;

        vis.insert(p);
        for(int i = 0; i < 4; i++){
            pair<int, int> temp = make_pair(p.first+dir[i], p.second+dir[i+1]);
            dfs(temp, heights, vis, heights[p.first][p.second]);
        }

    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        for(int i = 0; i < heights.size(); i++){
            dfs(make_pair(i, 0), heights, pac, heights[i][0]);
            dfs(make_pair(i, heights[0].size()-1), heights, atl, heights[i][heights[0].size()-1]);
        }

        for(int i = 0; i < heights[0].size(); i++){
            dfs(make_pair(0, i), heights, pac, heights[0][i]);
            dfs(make_pair(heights.size()-1, i), heights, atl, heights[heights.size()-1][i]);
        }

        vector<vector<int>> res;

        for(int i = 0; i < heights.size(); i++){
            for(int j = 0; j < heights[0].size(); j++){
                pair<int, int> temp = {i, j};
                if(pac.find(temp) != pac.end() and atl.find(temp) != atl.end()){
                    vector<int> v;
                    v.push_back(i),
                    v.push_back(j);

                    res.push_back(v);
                }   
            }
        }        

        return res;
    }
};
