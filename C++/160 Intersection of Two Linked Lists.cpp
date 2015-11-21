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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //cal the length
        ListNode *pA = headA, *pB = headB;
        int lenA=0, lenB=0, diff;
        while(pA){ pA = pA->next; lenA ++;}
        while(pB){ pB = pB->next; lenB++;}
        
        //longer one walk
        for(int i = 0; i < abs(lenA-lenB); i++){
            if(lenA > lenB)
                headA = headA->next;
            else
                headB = headB->next;
        }
        //walk together
        while(headA && headB){
            if(headA == headB) return headA;
            else{
                headA = headA->next;
                headB = headB->next;
            }
        }
        return nullptr;
        
    }
};
