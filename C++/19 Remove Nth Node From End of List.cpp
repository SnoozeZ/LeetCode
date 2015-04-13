#include "stdafx.h"
#include <iostream>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
//Runtime at LeetCode OJ is 8 ms. Time complexity is O(n).
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
		ListNode pre(0);
		pre.next = head;
        ListNode *pos1=head, *pos2=head, *pos3 = &pre;
		for(int i=0;i<n-1;i++,pos2 = pos2->next);
		while(pos2->next != NULL){
			pos3 = pos1;
			pos1 = pos1->next;
			pos2 = pos2->next;
		}
		pos3->next = pos1->next;
		return pre.next;
    }
};

int main(){
	ListNode a(1),b(2),c(3),d(4),e(5);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	ListNode *head = &a;
	Solution mySolution;
	head = mySolution.removeNthFromEnd(head, 3);
	while(head!=NULL){
		cout<<head->val;
		head = head->next;
	}
	system("pause");
}