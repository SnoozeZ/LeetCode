/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
 
 //Regard this problem as cloning the directed graph
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head) return head;
        unordered_map<RandomListNode*, RandomListNode*> peer;
        queue<RandomListNode*> q;
        RandomListNode* cur = new RandomListNode(head->label);
        peer[head] = cur;
        q.push(head);
        
        while(!q.empty()){
            RandomListNode* cur = q.front();
            q.pop();
            RandomListNode *p2 = peer[cur];
            //next ptr
            if(cur->next){
                if(peer.find(cur->next) != peer.end()){
                    p2->next = peer[cur->next];
                }else{
                    RandomListNode *tmp = new RandomListNode(cur->next->label);
                    p2->next = tmp;
                    peer[cur->next] = tmp;
                    q.push(cur->next);
                }
            }
            
            //random ptr
            if(cur->random){
                if(peer.find(cur->random) != peer.end()){
                    p2->random = peer[cur->random];
                }else{
                    RandomListNode *tmp = new RandomListNode(cur->random->label);
                    p2->random = tmp;
                    peer[cur->random] = tmp;
                    q.push(cur->random);
                }
            }
            
        }
        return cur;
        
    }
};
