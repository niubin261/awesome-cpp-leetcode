//
// Created by niubin on 18-2-6.
//

#include <cstdio>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL)return NULL;
        ListNode *p = head;
        ListNode *q = head->next;
        ListNode *pre = NULL;
        int i = 0;
        while (q != NULL){
            printf("i = %d",i++);
            ListNode *r = q->next;
            if (p == head){
                q->next = p;
                p->next = r;
                head = q;
            } else {
                q->next = p;
                p->next = r;
                pre->next = q;
            }
            pre = p;
            p = r;
            if(p == NULL)
                break;
            q = p->next;

        }
        return head;


    }
};
class Solution2 {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0);

        dummy.next = head;
        auto last = &dummy;
        while (last->next != NULL) {
            last = swapNext2(last);
        }

        return dummy.next;

    }

    ListNode* swapNext2(ListNode* prev) {
        auto first = prev->next;
        if (first == NULL) {
            return NULL;
        }

        auto second = first->next;
        if (second == NULL) {
            return first;
        }


        auto tail = second->next;

        prev->next = second;
        second->next = first;
        first->next = tail;

        return first;
    }
};
int main(){
    Solution solution;
    ListNode*head=new ListNode(1);
    head->next=new ListNode(2);
    head->next->next=new ListNode(3);
    head->next->next->next=new ListNode(4);
    head->next->next->next->next=new ListNode(5);
    ListNode*p=solution.swapPairs(head);
    while (p!=NULL){
        printf("%d\n",p->val);
        p=p->next;
    }

}
