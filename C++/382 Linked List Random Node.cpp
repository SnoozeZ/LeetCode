// // Naive O(1) time and O(n) space solution.
// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode(int x) : val(x), next(NULL) {}
//  * };
//  */
// class Solution {
// public:
//     /** @param head The linked list's head.
//         Note that the head is guaranteed to be not null, so it contains at least one node. */
//     //ListNode *head;
//     vector<int> nums;
//     Solution(ListNode* head) {
//         while(head != NULL) {
//             nums.push_back(head->val);
//             head = head->next;
//         }
        
//     }
    
//     /** Returns a random node's value. */
//     int getRandom() {
//         return nums[rand()%nums.size()];
//     }
// };

// /**
//  * Your Solution object will be instantiated and called as such:
//  * Solution obj = new Solution(head);
//  * int param_1 = obj.getRandom();
//  */


// For the follow up:

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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    ListNode *head;
    Solution(ListNode* head) {
        this->head = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int res = head->val;
        ListNode *newHead = head->next;
        int n = 2;
        while(newHead) {
            int tmp = rand()%n;
            if(tmp == 0) res = newHead->val;
            n++;
            newHead = newHead->next;
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
