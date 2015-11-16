//Merge sort solution with time complexity O(nlgn), but space not O(1)

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
    ListNode* sortList(ListNode* head) {
        if(!head) return head;
        int len=0;
        ListNode *cur = head;
        while(cur){
            len++;
            cur = cur->next;
        }
        
        return mergeSort(head, len);
    }
    
    ListNode* mergeSort(ListNode*& head, int len){//KEY: reference to *head
        if(1==len){//KEY: change head into head->next, if visit the leaf node of the search tree.
            ListNode *tmp = head;   
            head = head->next;  
            tmp->next = NULL;
            return tmp;
        }
        ListNode *left = mergeSort(head, len/2);
        ListNode *right = mergeSort(head, len - len/2);
        return merge(left, right);
    }
    
    ListNode *merge(ListNode *left, ListNode *right){
        ListNode *dummy = new ListNode(0);
        ListNode *cur = dummy;
        
        while(left || right){
            int leftVal = left? left->val : INT_MAX;
            int rightVal = right? right->val : INT_MAX;
            if(leftVal < rightVal){
                cur->next = left;
                left = left->next;
            }else{
                cur->next = right;
                right = right->next;
            }
            cur = cur->next;
        }
        return dummy->next;
    }
};
