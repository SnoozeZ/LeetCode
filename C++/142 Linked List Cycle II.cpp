/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {//time O(N)
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head) return NULL;
        ListNode *ptr1 = head, *ptr2 = head;
        while(true){
            //first step
            if(ptr2->next){
                ptr2 = ptr2->next;
                ptr1 = ptr1->next;
            }
            else return NULL;
            
            //second step
            if(ptr2->next) 
                ptr2 = ptr2->next;
            else return NULL;
            //compare
            if(ptr2 == ptr1) break; //meet for the first time
        }
        //find the start point of the cycle
        ptr2 = head;
        while(ptr2 != ptr1){
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        return ptr1;
    }
};
