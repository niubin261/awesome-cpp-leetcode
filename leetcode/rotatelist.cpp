//
// Created by niubin on 17-11-4.
//
/*
 * Given 1->2->3->4->5->NULL and k = 2,

return 4->5->1->2->3->NULL.*/
#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL)return NULL;
        if(k==0)return head;
        ListNode*pre=head;
        ListNode*end=head;

        for(int i=0;i<k;i++){
            end=end->next;
            if(end==NULL)
                return head;
        }
        while(end->next!=NULL){
            pre=pre->next;
            end=end->next;
        }
        ListNode*start=pre->next;
        pre->next=NULL;
        end->next=head;
        return start;
    }
};
int main(){
    Solution solution;
    ListNode*test=new ListNode(1);
    test->next=new ListNode(2);
    test->next->next=new ListNode(3);
    test->next->next->next=new ListNode(4);
    test->next->next->next->next=new ListNode(5);
    ListNode*ret=solution.rotateRight(test,5);
    ListNode* p=ret;
    while(p!=NULL){
        cout<<p->val;
        p=p->next;
    }
}