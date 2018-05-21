//
// Created by niubin on 17-12-4.
//


#include <cstdio>
#include <iostream>

//  Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)break;
        }
        return !(fast==NULL||fast->next==NULL);
    }
};
int main(){
    ListNode*test=new ListNode(1);
    test->next=new ListNode(2);
    test->next->next=new ListNode(3);
    test->next->next->next=new ListNode(4);
    test->next->next->next->next=test;
    Solution solution;
    std::cout<<solution.hasCycle(test);
}