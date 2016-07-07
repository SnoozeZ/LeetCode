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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(-1);
        ListNode *left, *right;
        dummy->next = head;
        left = dummy;
        bool flag = true;
        while(flag){
            int tmp = k;
            right = left;
            //find the k interval
            while(tmp-- != 0){
                if(!right->next){
                    flag = false;
                    break;
                }//stop
                right = right->next;
            }
            if(!flag) break;
            //reverse
            ListNode* before = left, *cur = left->next, *after;
            while(before != right){
                after = cur->next;
                cur->next = before;
                before = cur;
                cur = after;
            }
            //handle pointers
            ListNode* tmpLeft = left->next; 
            left->next->next = cur;
            left->next = before;
            left = tmpLeft;
        }
        
        return dummy->next;
    }
    
};
