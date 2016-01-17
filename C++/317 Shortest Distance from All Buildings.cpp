class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> distance(m, vector<int>(n, 0));
        vector<vector<int>> visit(m, vector<int>(n, 0));
        int buildingNum = 0, rlt = INT_MAX;
        //do BFS
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    buildingNum++;
                    auto tmpGrid = grid;
                    bfs(i, j, tmpGrid, distance, visit);
                }
            }
        }
        //find result
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(visit[i][j] == buildingNum)
                    rlt = min(rlt, distance[i][j]);
            }
        }
        return rlt == INT_MAX ? -1 : rlt;
    }
    
    void bfs(int x, int y, vector<vector<int>>& grid, vector<vector<int>>& distance, vector<vector<int>>& visit){
        queue<pair<int, int>> q;
        q.push(pair<int, int>(x, y));
        int step = 0;
        while(!q.empty()){
            int curLevelCount = q.size();
            while(curLevelCount--){//traverse this level
                int xx = q.front().first;
                int yy = q.front().second;
                q.pop();
                
                //meet the boundry
                if(xx == grid.size() || xx < 0 || yy == grid[0].size() || yy < 0){
                    continue;
                }
                if(step != 0 && grid[xx][yy] != 0) continue;
                
                //update status
                if(grid[xx][yy] != 1) visit[xx][yy]++;  //how many visitor have visit here
                distance[xx][yy] += step;
                grid[xx][yy] = -1; // visited
                
                q.push(pair<int, int>(xx+1, yy));
                q.push(pair<int, int>(xx-1, yy));
                q.push(pair<int, int>(xx, yy+1));
                q.push(pair<int, int>(xx, yy-1));
            }
            step++;
        }
    }
};
