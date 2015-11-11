/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
//time O(n)
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *before=NULL, *cur, *after=NULL;
        ListNode *mPtr, *nPtr;
        ListNode *dummy = new ListNode(0);
        mPtr = dummy;
        dummy->next = head;
        
        //find the two breakpoints
        for(int i=0; i<m-1;i++, mPtr = mPtr->next);
        nPtr = mPtr;
        for(int i=0;i<n-m+2;i++, nPtr = nPtr->next);
        
        //like the simple version
        cur = mPtr->next;
        while(cur!=nPtr){
            after = cur->next;
            if(cur == mPtr->next)
                cur->next = nPtr;   //link to the 1st breakpoint
            else
                cur->next = before; 
            before = cur;
            cur = after;
        }
        mPtr->next = before;//link to the 2nd breakpoint
        
        return dummy->next;
    }
};
