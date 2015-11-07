/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//O(n^2), 80ms
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode *dummy = new ListNode(INT_MIN);
        while(head){
            ListNode *p = dummy;
            ListNode *cur = head;
            head = head->next;
            while(p->next && p->next->val <= cur->val){
                p = p->next;
            }
            cur->next = p->next;
            p->next = cur;
        }
        return dummy->next;
            
    }
};
