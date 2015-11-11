/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//Easy
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* before = NULL, *cur = head, *after = NULL;
        while(cur){
            after = cur->next;
            cur->next = before;
            before = cur;
            cur = after;
        }
        return before;
        
    }
};
