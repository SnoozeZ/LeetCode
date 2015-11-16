//Graph clone, use a map to store the correlation of nodes in two graph; also record a node is visited or not.

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node) return node; 
        UndirectedGraphNode *p2 = new UndirectedGraphNode(node->label);
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> peer;//KEY
        queue<UndirectedGraphNode *> q;
        q.push(node);
        peer[node] = p2;
        
        while(!q.empty()){
            UndirectedGraphNode *cur = q.front();
            q.pop();
            p2 = peer[cur];
            
            for(UndirectedGraphNode* nb : cur->neighbors){
                if(peer.find(nb) != peer.end()){
                    //have existed
                    p2->neighbors.push_back(peer[nb]);
                }else{
                    //not existed, create new one
                    UndirectedGraphNode *tmp = new UndirectedGraphNode(nb->label);
                    peer[nb] = tmp;
                    p2->neighbors.push_back(tmp);
                    q.push(nb);
                }
            }
        }
        return peer[node];
    }
};
