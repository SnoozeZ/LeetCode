int INF = INT_MAX;
//DFS from all of the gates
class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        queue<pair<int, int>> q;
        //find the gate and add them into queue
        for(int i = 0; i < rooms.size(); i++){
            for(int j = 0; j < rooms[0].size(); j++){
                if(rooms[i][j] == 0)
                    q.push(pair<int, int>(i,j));
            }
        }
        //Let's do DFS!
        int level = -1;
        while(!q.empty()){
            int size = q.size();
            level++;
            while(size-- > 0){
                pair<int, int> curPos = q.front();
                q.pop();
                int x = curPos.first, y = curPos.second;
                //write distance
                if(rooms[x][y] == INF) rooms[x][y] = level;
                //BFS
                if(x-1 >= 0 && rooms[x-1][y] == INF) q.push(pair<int, int>(x-1, y));
                if(x+1 < rooms.size() && rooms[x+1][y] == INF) q.push(pair<int, int>(x+1, y));
                if(y-1 >= 0 && rooms[x][y-1] == INF) q.push(pair<int, int>(x, y-1));
                if(y+1 < rooms[0].size() && rooms[x][y+1] == INF) q.push(pair<int, int>(x, y+1));
                
            }
        }
    }
};
