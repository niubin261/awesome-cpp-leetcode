//
// Created by niubin on 17-9-25.
//

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *dummy = new ListNode(0);
        ListNode *tmp = dummy;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                tmp->next = l1;
                l1 = l1->next;
            } else {
                tmp->next = l2;
                l2 = l2->next;
            }
            tmp = tmp->next;
        }
        if (l1 != NULL) tmp->next = l1;
        else tmp->next = l2;
        return dummy->next;
    }
};

int main() {
    ListNode *l1 = new ListNode(8);
    l1->next = new ListNode(9);
    l1->next->next = new ListNode(10);
    l1->next->next->next = new ListNode(11);
    ListNode *l2 = new ListNode(1);
    l2->next = new ListNode(4);
    l2->next->next = new ListNode(7);
    l2->next->next->next = new ListNode(9);
    Solution solution;
    ListNode *p = solution.mergeTwoLists(l1, l2);
    while (p != NULL) {
        cout << p->val;
        p = p->next;
    }

}