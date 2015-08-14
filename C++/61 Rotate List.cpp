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
    ListNode* rotateRight(ListNode* head, int k) {//time O(N), space O(1), 12ms AC.
        if(head == NULL) return NULL;
        ListNode *ptr1 = head, *ptr2 = head, *result;
        k %= findLength(head);
        
        int count = 0;
        while(ptr2->next!=NULL){
            ptr2 = ptr2->next;
            if(count == k){
                ptr1 = ptr1->next;
                continue;
            }
                count ++;
        }
        
        ptr2->next = head;
        result = ptr1->next;
        ptr1->next = NULL;
        
        return result;
    }
    
    int findLength(ListNode* head){
        int len = 1;
        ListNode* tmp = head;
        while(tmp->next != NULL) {
            tmp = tmp->next;
            len++;
        }
        return len;
    }
};
