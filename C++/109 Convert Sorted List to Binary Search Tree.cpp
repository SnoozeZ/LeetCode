/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //time O(nlgn)
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode *tail = head;
        
        for(;tail->next!=NULL; tail = tail->next);
        return findMid(head, tail);
    }
    TreeNode* findMid(ListNode *head, ListNode *tail){
        if(!head || !tail ||tail->next == head)
            return NULL;
        
        //find mid
        ListNode *mid = head, *ptr2 = head, *premid=NULL;
        while(ptr2 != tail){
            ptr2 = ptr2->next;
            if(ptr2 != tail){
                ptr2 = ptr2->next;
                premid = mid;
                mid = mid->next;
            }
        }
        TreeNode *rootPtr = new TreeNode(mid->val);
        rootPtr->left = findMid(head, premid);
        rootPtr->right = findMid(mid->next, tail);
        return rootPtr;
    }
};
