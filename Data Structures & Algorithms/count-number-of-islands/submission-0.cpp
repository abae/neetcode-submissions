class Solution {
private:
    void searchIsland(int x, int y, std::set<std::pair<int, int>>& set, const vector<vector<char>>& grid){
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        set.insert({x, y});
        for(int i = 0; i < 4; ++i){
            int newX = x + dx[i];
            int newY = y + dy[i];
            if(newX >= 0 && newX < grid[0].size() && newY >= 0 && newY < grid.size() && grid[newY][newX] == '1' && !set.contains({newX, newY})){
                searchIsland(newX, newY, set, grid);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        std::set<std::pair<int, int>> islandCells;
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[0].size(); ++j){
                if(grid[i][j] == '0' || islandCells.contains({j, i})){
                    continue;
                }
                ++count;
                searchIsland(j, i, islandCells,grid);
            }
        }
        return count;
    }
};