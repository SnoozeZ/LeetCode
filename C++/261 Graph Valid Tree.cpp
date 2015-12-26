/*
//topology sort doesn't work: hard to determine whether a graph is connected or not 
class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        unordered_map<int, set<int>> nodes;
        for(auto edge : edges){//init the graph
            nodes[edge.first].insert(edge.second);
            nodes[edge.second].insert(edge.first);
        }
        vector<int> leaves;
        for(auto node : nodes){//init leaves (whose degree is 1)
            if(node.second.size() == 1)
                leaves.push_back(node.first);
        }
        while(!leaves.empty()){
            vector<int> newLeaves;
            for(int leaf : leaves){
                int neighbor = *(nodes[leaf].begin());
                nodes[neighbor].erase(leaf);//delete neighbor
                if(nodes[neighbor].size() == 1){
                    newLeaves.push_back(neighbor);//neighbor is leaf if its degree is one
                }
                nodes.erase(leaf);//delete the current leaf
            }
            leaves = newLeaves;
        }
        return nodes.empty();
    }
};*/

//DFS Solution.
/*
class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        unordered_map<int, set<int>> nodes;
        vector<bool> visit(n, false);
        for(auto edge : edges){//init the graph
            nodes[edge.first].insert(edge.second);
            nodes[edge.second].insert(edge.first);
        }
        if(!dfs(-1, 0, nodes, visit))//circle existed
            return false;
        for(bool v : visit){
            if(!v) return false;
        }
        return true;
        
    }
    bool dfs(int parent, int node, unordered_map<int, set<int>>& nodes, vector<bool>& visit){
        if(visit[node]) return false;
        visit[node] = true;
        for(auto nbr : nodes[node]){
            if(nbr == parent) continue; //avoid the lookback from child to parent
            if(!dfs(node, nbr, nodes, visit))
                return false;
        }
        return true;
    }
};*/


//Union Find Solution.
class UnionFind{
public:
    vector<int> ids;   //node -> group id
    int count;  //number of different groups
    
    UnionFind(int size){
        count = size;
        ids.resize(size);
        for(int i = 0; i < size; i++){
            ids[i] = i;
        }
    }
    
    bool unionn(int node1, int node2){
        int id1 = find(node1);
        int id2 = find(node2);
        if(id1 != id2){
            ids[id1] = id2;//change parent 
            count--;
            return true;
        }else{
            return false; // have circle
        }
    }
    
    int find(int node){
        while(ids[node] != node)    //until find the root(group number)
            node = ids[node];
        return node;
    }
    
    int getCount(){
        return count;
    }
};
    
class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        UnionFind uf(n);
        for(auto edge : edges){//init the graph
            if(uf.unionn(edge.first, edge.second) == false)
                return false; //have circle
        }
        return uf.getCount() == 1;
    }
};


