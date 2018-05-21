//
// Created by niubin on 17-9-17.
#include <vector>
#include <iostream>
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
// Consider the length of the two links is not the same
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*header=NULL;
        ListNode*p1=l1;
        ListNode*p2=l2;
        ListNode*rear=NULL;
        ListNode*p=NULL;
        int carryBit=0;
        int value;
        while(p1!=NULL&&p2!=NULL){
            value=p1->val+p2->val+carryBit;
            if(value>9){
                carryBit=1;
                value=value-10;
            } else {
                carryBit=0;
            }
            p1=p1->next;
            p2=p2->next;
            p=new ListNode(value);
            if(header== NULL){
                header=p;

            } else {
                rear->next=p;
            }
            rear=p;
        }
        if(p1==NULL&&p2==NULL){

            if(carryBit!=0){
                p=new ListNode(1);
                rear->next=p;
            }
            return header;
        } else if (p1==NULL&&p2!=NULL){
            while(p2!=NULL){
                value=p2->val+carryBit;
                if(value>9){
                    carryBit=1;
                    value=value-10;
                } else {
                    carryBit=0;
                }
                p2=p2->next;
                p=new ListNode(value);
                rear->next=p;
                rear=p;
            }

        } else {
            while(p1!=NULL){
                value=p1->val+carryBit;
                if(value>9){
                    carryBit=1;
                    value=value-10;
                } else {
                    carryBit=0;
                }
                p1=p1->next;
                p=new ListNode(value);
                rear->next=p;
                rear=p;
            }

        }
        if(carryBit!=0){
            p=new ListNode(1);
            rear->next=p;
            rear=p;
        }
        return header;
    }
};
int main(){
    Solution solution;
    ListNode*l1=new ListNode(9);
    l1->next= new ListNode(9);
    ListNode*l2=new ListNode(1);
    ListNode*p=solution.addTwoNumbers(l1,l2);
    while(p!=NULL){
        cout<<p->val;
        p=p->next;
    }
    return 0;
}