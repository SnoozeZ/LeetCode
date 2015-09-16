tion for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
**/
 
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {//Time O(N), space O(1)
        if (!head) return head;
        ListNode preHead(0);
        preHead.next = head;
        
        ListNode *ptr1 = &preHead, *ptr2 = &preHead;
        for(;ptr1->next && ptr1->next->val < x; ptr1 = ptr2 = ptr2->next);
        
        while(ptr2->next){
            if(ptr2->next->val < x){
                ListNode *tmp = ptr2->next;
                //swap
                ptr2->next = tmp->next;
                tmp->next = ptr1->next;
                ptr1->next = tmp;
                
                ptr1 = ptr1->next;
            }else{// If not success, has to move ptr2 to the next ListNode.
                ptr2 = ptr2->next;
            }
        }
        return preHead.next;
        
    }
};
