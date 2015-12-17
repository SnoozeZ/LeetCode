/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//32ms
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dummy = new ListNode(-1), *p1 = dummy, *p2 = dummy;
        dummy->next = head;
        
        while(p2 && p2->next){
            p2 = p2->next;
            while(p2 && p2->val == val){
                p2 = p2->next;
            }
            p1->next = p2;
            p1 = p2;
        }
        return dummy->next;
    }
};

/*
//easy understanding but slow
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *p = dummy;
        
        while(head){
            if(head->val == val){
                p->next = head->next;
            }else{
                p = head;
            }
            head = head->next;
        }
        return dummy->next;
    }
};*/

/*
//36ms, recursive!
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return NULL;
        head->next = removeElements(head->next, val);
        return head->val==val ? head->next : head;
        
    }
};*/


