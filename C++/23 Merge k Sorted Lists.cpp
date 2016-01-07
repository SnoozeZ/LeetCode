/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *rlt = new ListNode(-1);
        ListNode *cur = rlt;
        priority_queue<ListNode*, vector<ListNode*>, decltype(&cmp)> min_heap(&cmp);
        //add the head of the lists
        for(auto listNode : lists){
            if(listNode) min_heap.push(listNode);
        }
        //iterate till heap -> empty
        while(!min_heap.empty()){
            cur->next = min_heap.top();
            cur = cur->next;
            min_heap.pop();
            if(cur->next)
                min_heap.push(cur->next);
        }
        return rlt->next;
    }
    
    static bool cmp(ListNode* l1, ListNode* l2){
        return l1->val > l2->val;
    }
};
