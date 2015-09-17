/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
//Solution 1 with HashMap. 60ms time O(n) and space O(n)
class Solution { 
public:
    bool hasCycle(ListNode *head) {
        if(!head) return false;
        
        map<ListNode*, bool> traverse;
        traverse[head] = true;
        
        while(head->next){
            head = head->next;
            if(traverse.find(head) != traverse.end()){ // Has loop
                return true;
            }else{
                traverse[head] = true;
            }
        }
        
        return false; // Doesn't have loop 
    }
};*/


//Solution 2 with Two Pointers. 12ms, time O(n), space O(1)
class Solution { 
public:
    bool hasCycle(ListNode *head) {
        if(!head) return false;
        ListNode *slow = head, *fast = head;
        
        while(fast->next){
            fast = fast->next;// Fast's first step
            if(fast == slow) return true;
            if(!fast->next) break;
            
            fast = fast->next;// Fast's second step
            if(fast == slow) return true;
            
            slow = slow->next;//Slow's first step
        }
        return false;//Fast meets the tail
    }
};
