class Node {
public:
    string type;
    int x;
    int h;
    Node(string tt, int xx, int hh):x(xx), h(hh),type(tt){}
};

bool cmp(Node n1, Node n2){
    if(n1.x != n2.x)
        return n1.x < n2.x;
    if(n1.type == "start" && n2.type == "start"){
        return n1.h > n2.h;//big to small
    }else if(n1.type == "end" && n2.type == "end"){
        return n1.h < n2.h; //small to big
    }else{
        return n1.type == "start";
    }
}

bool queueCmp(Node n1, Node n2){
    return n1.h < n2.h;
}

class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> rlt;
        if(buildings.empty()) return rlt;
        //construct nodes
        vector<Node> nodeVec;
        for(auto building : buildings){
            Node n1("start", building[0], building[2]);
            Node n2("end", building[1], building[2]);
            nodeVec.push_back(n1);
            nodeVec.push_back(n2);
        }
        //sort the node
        sort(nodeVec.begin(), nodeVec.end(), cmp);
        for(int i = 0; i < nodeVec.size()-1; i++){
            if(nodeVec[i].x == nodeVec[i+1].x && nodeVec[i].h == nodeVec[i+1].h){
                nodeVec.erase(nodeVec.begin() + i);
                nodeVec.erase(nodeVec.begin() + i);
            }
        }
        //lets go
        unordered_map<int, int> valid;// height->count. To check the height valid or not.
        priority_queue<Node, vector<Node>, decltype(&queueCmp)> maxHeap(&queueCmp);
        int pre=-1, cur=-1;
        for(Node node : nodeVec){
            if(node.type == "start"){
                maxHeap.push(node);
                //while(valid[maxHeap.top().h] == 0) maxHeap.pop();// remove invalid
                //rlt.push_back(pair<int, int>(maxHeap.top().x, maxHeap.top().h));
            }else{
                valid[node.h]++;    //will be pop next time
                while(!maxHeap.empty() && valid[maxHeap.top().h] > 0){
                    valid[maxHeap.top().h]--;
                    maxHeap.pop();
                }
            }
            int cur = maxHeap.empty() ? 0 : maxHeap.top().h;
            if(pre != cur){
                rlt.push_back(pair<int, int>(node.x, cur));
            }
            pre = cur;
        }
        //rlt.push_back(pair<int, int>(nodeVec.back().x, 0));
        return rlt;
    }
};
