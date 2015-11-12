/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return nullptr;
        ListNode *ptr1 = head, *ptr2 = head;
        while(ptr1->next){
            while(ptr2->next && ptr2->val == ptr2->next->val) ptr2 = ptr2->next;
            ptr1->next = ptr2->next;
            if(ptr1->next){
                ptr1 = ptr1->next;
                ptr2 = ptr1;
            }
        }
        return head;
    }
};*/
//more concise
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;
        ListNode *cur = head;
        while(cur){
            while(cur->next && cur->val == cur->next->val){
                cur->next = cur->next->next;
            }
            cur = cur->next;
        }
        return head;
    }
        
};

