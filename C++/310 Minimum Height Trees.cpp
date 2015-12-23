class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<int> rlt;
        if(n == 1){
            rlt.push_back(0);
            return rlt;
        }
        //construct map
        unordered_map<int, unordered_set<int>> map;
        for(auto p : edges){
            map[p.first].insert(p.second);
            map[p.second].insert(p.first);
        }
        //put leaves into leaves vector
        vector<int> leaves;
        for(auto p : map){
            if(p.second.size() == 1)
                leaves.push_back(p.first);
        }
        
        //iteration, till remain node less or equal than 2
        int count = n;
        while(count > 2){
            count -= leaves.size();
            vector<int> newLeaves;  // new leaves
            for(int leaf : leaves){
                int nbr = *(map[leaf].begin());
                map[nbr].erase(leaf);
                if(map[nbr].size() == 1) newLeaves.push_back(nbr);
            }
            leaves = newLeaves;
        }
        return leaves;
    }
};
