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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode* ptr1 = dummy, *ptr2 = head;
        
        while(ptr2){
            bool flag=false;
            while(ptr2->next && ptr2->val == ptr2->next->val) ptr2 = ptr2->next;
            if(ptr1->next == ptr2)
                ptr1 = ptr1->next;
            else
                ptr1->next = ptr2->next;
            ptr2 = ptr2->next;
        }
        return dummy->next;
    }
};
