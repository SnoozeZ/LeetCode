// Map of map and DFS
class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        unordered_map<string, unordered_map<string, double>> m;
        vector<double> result;
        for(int i = 0; i < values.size(); i++) {
            auto equa = equations[i];
            m[equa.first][equa.second] = values[i];
            //m[equa.second][equa.second] = 1.0;
            if(values[i] != 0) {
                m[equa.second][equa.first] = 1 / values[i];
                //m[equa.first][equa.first] = 1.0;
            }
        }
        // DFS
        for(int i = 0; i < queries.size(); i++) {
            unordered_set<string> visited;
            double tmp = dfs(m, visited, queries[i].first, queries[i].second);
            if(!tmp) {
                result.push_back(-1.0);
            } else {
                result.push_back(tmp);
            }
        }
        
        return result;
    }
    
    double dfs(unordered_map<string, unordered_map<string, double>>& m, unordered_set<string>& visited, string up, string down) {
        if(m[up].count(down)) return m[up][down];
        
        for(auto p : m[up]) {
            if(!visited.count(p.first)) {
                visited.insert(p.first);
                double tmp = dfs(m, visited, p.first, down);
                if(tmp) return p.second * tmp;
            }
        }
        
        return 0;
    }
};
