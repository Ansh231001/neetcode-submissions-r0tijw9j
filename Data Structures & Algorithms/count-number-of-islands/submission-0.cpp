class Solution {
public:

    void bfs(vector<vector<char>>& grid, vector<vector<int>>& visited, pair<int, int> start, vector<int>& dir){
        queue<pair<int, int>> q;
        q.push(start);
        visited[start.first][start.second] = 1;

        while(!q.empty()){
            auto temp = q.front();
            q.pop();

            // traversal in 4 directions
            for(int i = 0; i < 4; i++){
                int x = temp.first + dir[i];
                int y = temp.second + dir[i+1];

                if(x < 0 or x >= grid.size() or y < 0 or y >= grid[0].size() 
                   or grid[x][y] == '0' or visited[x][y])
                    continue;

                visited[x][y] = 1;
                q.push({x, y});
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int count = 0;

        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
        vector<int> dir = {-1,0,1,0,-1};

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    count++;
                    bfs(grid, visited, {i,j}, dir);
                }
            }
        }

        return count;
    }
};