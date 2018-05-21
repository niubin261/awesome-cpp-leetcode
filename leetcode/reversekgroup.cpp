//
// Created by niubin on 17-9-19.
//

#include <iostream>
#include <map>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if(head==NULL)return NULL;
        ListNode*dummy=new ListNode(0);
        dummy->next=head;
        ListNode*pre=dummy;
        ListNode*cur=head;
        ListNode*next;
        int cnt=1;
        while(cur!=NULL){
            cur = cur->next;
            cnt++;
            if (cnt == k&&cur!=NULL) {
                    pre = reverseList(pre, cur);
                    cnt = 1;
                    cur = pre->next;
                }
        }
        return dummy->next;
    }

private:
    ListNode* reverseList(ListNode *pre, ListNode *rear) {
        ListNode*end=rear->next;
        if(pre==NULL || pre->next==NULL)
            return pre;
        ListNode *head = pre->next;
        ListNode *cur = pre->next->next;
        while(cur!=end)
        {
            ListNode *next = cur->next;
            cur->next = pre->next;
            pre->next = cur;
            cur = next;
        }
        head->next = end;
        return head;

    }
};
int main(){
    ListNode*head=new ListNode(1);
    head->next=new ListNode(2);
    head->next->next=new ListNode(3);
    head->next->next->next=new ListNode(4);
    head->next->next->next->next=new ListNode(5);
    Solution solution;

    ListNode*p=solution.reverseKGroup(head,5);;
    while (p!=NULL){
        cout<<p->val;
        p=p->next;
    }
}