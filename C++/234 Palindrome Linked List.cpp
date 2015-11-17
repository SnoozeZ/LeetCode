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
    bool isPalindrome(ListNode* head) {
        if(!head) return true;
        ListNode *slow=head, *fast = head;
        //find middle
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        //reverse the second half
        ListNode *before = NULL, *after = NULL, *cur = slow->next;
        while(cur){
            after = cur -> next;
            cur->next = before;
            before = cur;
            cur = after;
        }
        //compare
        while(before){
            if(before->val != head->val)
                return false;
            head = head->next;
            before = before->next;
        }
        return true;
    }
};
