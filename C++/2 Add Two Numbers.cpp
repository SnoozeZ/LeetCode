#include <iostream>
#include <string>

using namespace std;

/*Definition for singly-linked list.*/
struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};

//Runtime at LeetCode OJ is 52 ms.
//No extra use of memory.
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int carry = 0, val_1=0, val_2 = 0;
		bool flag = false;	//to mark whether l2 is linked to l1 or not.
		ListNode *ptr_l1 = l1, *ptr_l2 = l2, *tmp;
		while(NULL != ptr_l1 || (NULL != ptr_l2 && !flag)){ //not at the tails of l1 and l2.
			if(NULL == ptr_l1){ //link l2's rest to l1's tail.
				tmp->next = ptr_l2;
				ptr_l1 = ptr_l2;
				flag = true;
			}
			val_1 = ptr_l1->val;
			carry += val_1;
			if(NULL != ptr_l2 && !flag){
				val_2 = ptr_l2->val;
				carry += val_2;
				ptr_l2 = ptr_l2 -> next;	
			}
			ptr_l1->val = carry % 10;//Using l1 to store the result.
			carry /= 10;
			if(NULL == ptr_l1 -> next)
				tmp = ptr_l1;
			ptr_l1 = ptr_l1 -> next;
		}
		if(1 == carry)// add the new carry bit.
			tmp->next = new ListNode(1);
		return l1;
    }
};

int main(){
	ListNode l1(0);
	ListNode l4(7), l5(3);

	l4.next = &l5;

	Solution mySolution;
	ListNode *result = mySolution.addTwoNumbers(&l1,&l4);

	system("pause");
	
}