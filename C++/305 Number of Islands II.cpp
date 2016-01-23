//two dimentional union find problem
//Idea: after adding a node in the grid, check its four neighbors. If exist, union them.

class UnionFind {
private:
    vector<vector<pair<int, int>>> grid;
    int m,n;
    int uniqueNum;
public:
    UnionFind(int x, int y){
        m = x;
        n = y;
        uniqueNum = 0;
        //init, (-1, -1) means no island here
        vector<vector<pair<int, int>>> tmp(m, vector<pair<int,int>>(n, pair<int, int>(-1,-1)));
        grid = tmp;
    }
    
    void Union(pair<int, int> p1, pair<int, int> p2){
        //tree version union
        while(find(p1) != p1) p1 = find(p1);
        while(find(p2) != p2) p2 = find(p2);
        if(p1 != p2){
            grid[p1.first][p1.second] = p2;
            uniqueNum --;
        }
    }
    
    pair<int, int> find(pair<int, int> p){
        return grid[p.first][p.second];
    }
    
    void add(pair<int, int> p){
        uniqueNum++;
        int x = p.first, y = p.second;
        //give the island tag
        grid[x][y] = pair<int, int>(x, y);
        //check its neighbors
        checkAndUnion(p, pair<int, int>(x+1, y));
        checkAndUnion(p, pair<int, int>(x-1, y));
        checkAndUnion(p, pair<int, int>(x, y+1));
        checkAndUnion(p, pair<int, int>(x, y-1));
    }
    
    void checkAndUnion(pair<int, int> p1, pair<int, int> nbr){//check its neighbor and union them
        if(nbr.first < 0 || nbr.first >= m || nbr.second < 0 || nbr.second >=n)//Hmm... out of boundry
            return;
        pair<int, int> invalid(-1, -1);
        if(grid[nbr.first][nbr.second] == invalid) // Hmm.. no island of this neighbor
            return;
        //valid, let's union them!
        Union(p1, nbr);
    }
    
    int getUniqueNum(){
        return uniqueNum;
    }
};


class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        UnionFind uf(m, n);
        vector<int> rlt;
        for(auto p : positions){
            uf.add(p);   
            rlt.push_back(uf.getUniqueNum());
        }
        return rlt;
    }
};
