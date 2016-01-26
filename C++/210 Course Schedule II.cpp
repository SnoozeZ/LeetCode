class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        //create graph and cal indegree
        map<int, set<int>> nbr;
        vector<int> inDegree(numCourses);
        for(auto p : prerequisites){
            if(nbr[p.second].find(p.first) == nbr[p.second].end())  //to avoid the duplicate edge 
                inDegree[p.first]++;
            nbr[p.second].insert(p.first);
        }
        //init the queue
        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }
        //do BFS
        vector<int> rlt;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            rlt.push_back(cur);
            for(int neighbor : nbr[cur]){
                if(--inDegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }
        //check OK or not
        for(auto p : inDegree){
            if(p != 0)
                return vector<int>();   //failed, circle existed
        }
        return rlt;
        
    }
};
