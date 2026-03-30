class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == 0)
                    q.push(make_pair(i, j));
                
            }
        }

        //bfs
        vector<int> dir = {-1, 0, 1 , 0, -1};
        int dist = 0;
        while(!q.empty()){
            auto temp = q.front();
            q.pop();

            for(int i = 0; i < 4; i++){
                int x = temp.first + dir[i];
                int y = temp.second + dir[i+1];

                if(x < 0 or x >= grid.size() or y < 0 or y >= grid[0].size()
                or grid[x][y] != INT_MAX) continue;

                grid[x][y] = grid[temp.first][temp.second] + 1;
                q.push({x,y});
            }
        }
    }
};
