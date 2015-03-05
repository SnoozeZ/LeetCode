#include <iostream>
#include <string>
#include <stack>

using namespace std;
//Runtime at LeetCode OJ is 4 ms.



struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if(head == NULL)
            return 0;
        ListNode preHead(0);
        preHead.next = head;
        ListNode *ptr_1 = &preHead, *ptr_2 = head, *tmp;
        while(1){
            tmp = ptr_2->next;
            if(tmp == NULL)
                break;
            ptr_2->next = ptr_2->next->next;//1
            tmp->next = ptr_2;//2
            ptr_1->next = tmp;//3

            if(ptr_2->next == NULL)
                break;
            ptr_1 = ptr_2;
            ptr_2 = ptr_2->next;
        }
        return preHead.next;
    }

};

int main(){
    ListNode l1(1);
    ListNode l2(2);
    ListNode l3(3), l4(4);

    l1.next = &l2;
    l2.next = &l3;
    //l3.next = &l4;

    Solution mySolution;
    ListNode *result = mySolution.swapPairs(&l1);

    system("pause");
}