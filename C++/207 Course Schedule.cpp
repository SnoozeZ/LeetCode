//Topological sorting
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        //construct graph
        vector<unordered_set<int>> need(numCourses);
        for(auto p:prerequisites){
            need[p.second].insert(p.first);
        }
        
        //cal in-degree
        vector<int> inDegree(numCourses);
        for(auto set : need)
            for(auto node : set)
                inDegree[node]++;
        //Create queue
        queue<int> search;
        for(int i=0; i<inDegree.size();i++){
            if(0==inDegree[i])
                search.push(i);
        }
        //BFS
        while(!search.empty()){
            numCourses--;
            int cur = search.front();
            search.pop();
            for(auto course:need[cur]){
                if(--inDegree[course] == 0){
                    search.push(course);
                }
            }
        }
        return numCourses==0;
    }
};
