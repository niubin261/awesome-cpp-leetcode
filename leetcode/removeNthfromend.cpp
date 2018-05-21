//
// Created by niubin on 17-10-12.
//
//two pass algorithm
#include <iostream>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len=0;
        if(head==NULL)return NULL;

        ListNode*p=head;
        while(p!=NULL){
            len++;
            p=p->next;
        }
        int pos=len-n+1;

        if(pos==1){
            if(len==1){
                return NULL;
            }
            head=head->next;
            return head;
        }
        int j=1;

        ListNode*pre=head;
        ListNode*next=head;
        while(j<pos-1){

            pre=pre->next;

            j++;
        }
        next=pre->next->next;
        pre->next=next;
        return head;

    }
};
int main(){
    Solution solution;
    ListNode*head=new ListNode(1);
    head->next=new ListNode(2);
    head->next->next=new ListNode(3);
    head->next->next->next=new ListNode(4);
    head->next->next->next->next=new ListNode(5);
    head=solution.removeNthFromEnd(head,5);
    ListNode*p=head;
    while(p!=NULL){
        cout<<p->val;
        p=p->next;
    }
}