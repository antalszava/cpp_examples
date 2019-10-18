/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>
#include <vector>
#include "stdlib.h"

class ListNode {
public:
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};


ListNode* merge_two_lists(ListNode* l1, ListNode* l2) {

  // ListNode* spliced = l1;
  // ListNode* temp = spliced;

  // std::vector<int> spliced_int;
  // ListNode* s1 = l1;
  // ListNode* s2 = l2;
  
  // while (s1 != NULL || s2 != NULL){
  //   if (s1 != NULL)
  //     spliced_int.push_back(s1->val);
  //   if (s2 != NULL)
  //     spliced_int.push_back(s2->val);
  //   s1 = s1->next;
  //   s2 = s2->next;
  // }
  // for (int i = 0; i < spliced_int.size(); i++){
  //   std::cout << spliced_int[i] << std::endl;
  // }
  ListNode* spliced;
  std::vector<ListNode*> spliced_list;
  ListNode* s1 = l1;
  ListNode* s2 = l2;
  
  
  while (s1 != NULL || s2 != NULL){
    if (s1 != NULL && (s2 == NULL || s1->val <= s2->val)){
      spliced_list.push_back(s1);
      s1 = s1->next;
    }
    if (s2 != NULL && (s1 == NULL || s2->val <= s1->val)){
      spliced_list.push_back(s2);
      s2 = s2->next;  
    }
    
  }

  for (int i = 0; i < spliced_list.size(); i++){
    spliced = spliced_list[i];
    spliced->next = spliced_list[i+1];
    spliced = spliced->next;
  }
       
  
  return l1;
}


int main(int argc, char *argv[])
{
  ListNode* l1_head = new ListNode(1);
  ListNode* l1_first = new ListNode(3);
  l1_head->next = l1_first;
  ListNode* l1_second = new ListNode(4);
  l1_first->next = l1_second;
  
  ListNode* l2_head = new ListNode(1);
  ListNode* l2_first = new ListNode(2);
  l2_head->next = l2_first;
  ListNode* l2_second = new ListNode(4);
  l2_first->next = l2_second;

  ListNode* spliced = merge_two_lists(l1_head, l2_head);
  
  while(spliced != NULL){
    std::cout << spliced->val << std::endl;
    spliced = spliced->next;
  }

  
  return 0;
}

  


//better recursion
ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if (l1 == null) {
            return l2;
        }
        else if (l2 == null) {
            return l1;
        }
        else if (l1.val < l2.val) {
            l1.next = mergeTwoLists(l1.next, l2);
            return l1;
        }
        else {
            l2.next = mergeTwoLists(l1, l2.next);
            return l2;
        }

    }



//better iteration
ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        // maintain an unchanging reference to node ahead of the return node.
        ListNode prehead = new ListNode(-1);

        ListNode prev = prehead;
        while (l1 != null && l2 != null) {
            if (l1.val <= l2.val) {
                prev.next = l1;
                l1 = l1.next;
            } else {
                prev.next = l2;
                l2 = l2.next;
            }
            prev = prev.next;
        }

        // exactly one of l1 and l2 can be non-null at this point, so connect
        // the non-null list to the end of the merged list.
        prev.next = l1 == null ? l2 : l1;

        return prehead.next;
    }
