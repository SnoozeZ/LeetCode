// Construct the graph and do DFS.
class Solution {
public:
    int totalTicketCount;
    unordered_map<string, vector<string>> neighbor;
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        // Build the graph
        for(pair<string, string> p : tickets) {
            neighbor[p.first].push_back(p.second);
        }
        // Sort
        for(auto p : neighbor) {
            sort(p.second.begin(), p.second.end());
            neighbor[p.first] = p.second;   // Its not got by reference.
        }
        // DFS
        totalTicketCount = tickets.size();
        vector<string> path({"JFK"});
        dfs("JFK", path);
        return path;
    }
    
    bool dfs(string name, vector<string>& path) {
        if (path.size() == totalTicketCount+1) 
            return true; 
        for(int i=0; i < neighbor[name].size(); i++) {
            string nbr = neighbor[name][i];
            neighbor[name].erase(neighbor[name].begin()+i);
            path.push_back(nbr);
            if (dfs(nbr, path)) 
                return true;
            path.pop_back();
            neighbor[name].insert(neighbor[name].begin()+i, nbr);
        }
        return false;
    }
};
