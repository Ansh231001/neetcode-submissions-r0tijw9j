class Solution {
public:

    int bfs(vector<vector<int>>& grid, vector<vector<int>>& visited, pair<int, int> start, vector<int>& dir){
        queue<pair<int, int>> q;
        q.push(start);
        visited[start.first][start.second] = 1;
        int area = 1;

        while(!q.empty()){
            auto temp = q.front();
            q.pop();

            for(int i = 0; i < 4; i++){
                int x = temp.first + dir[i];
                int y = temp.second + dir[i+1];

                if(x < 0 or x >= grid.size() or y < 0 or y >= grid[0].size()
                or grid[x][y] == 0 or visited[x][y] == 1) continue;
                
                else {
                    area++;
                    visited[x][y] = 1;
                    q.push({x, y});
                }
            }
        }

        return area;
    }


    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
        vector<int> dir = {-1,0,1,0,-1};

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0;  j < grid[i].size(); j++){
                if(grid[i][j] == 1 and !visited[i][j]){
                    pair<int, int> p = make_pair(i, j);
                    maxArea = max(maxArea, bfs(grid, visited, p, dir));
                }
            }
        }

        return maxArea;
    }
};
