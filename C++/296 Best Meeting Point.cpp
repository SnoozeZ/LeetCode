class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        int rlt = 0;
        if(grid.empty()) return rlt;
        vector<int> x, y;
        //init
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    x.push_back(i);
                    y.push_back(j);
                }
            }
        }
        
        //sort and find meet point
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        int meetPoint_x = x[x.size()/2];
        int meetPoint_y = y[y.size()/2];
        
        //calculate result
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    rlt += abs(i - meetPoint_x);
                    rlt += abs(j - meetPoint_y);
                }
            }
        }
        return rlt;
    }
};
