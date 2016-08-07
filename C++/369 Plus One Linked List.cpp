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
    ListNode* plusOne(ListNode* head) {
        int tmp = helper(head);
        if(0 == tmp){
            return head;
        }else{
            ListNode *newHeaed = new ListNode(1);
            newHeaed->next = head;
            return newHeaed;
        }
    }
    
    int helper(ListNode* node){
        if(!node) return 1; //last null node
        
        int tmp = helper(node->next);
        node->val += tmp;
        if(node->val == 10){
            node->val = 0;
            return 1;
        }else{
            return 0;
        }
    }
};
