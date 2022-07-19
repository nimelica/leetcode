#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // null <- 1-> 2-> 3->null
        // null->3->2->1->nullptr
        // prev -> curr ->currNext
        if(!head or !head->next) return head;
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* nxt = nullptr;
        
        while(curr){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
      
    // merge two-sorted lists
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1 and !list2) 
            return nullptr;
        else if(!list1 or !list2){
            return !list1 ? list2 : list1;
        }
        
        ListNode prev(-1);
        ListNode* head = &prev;
        
        while(list1 != nullptr and list2 != nullptr){
            if(list1->val < list2->val){
                head->next = list1;
                list1 = list1->next;
            }
            else{
                head->next = list2;
                list2 = list2->next;
            }
            head = head->next;
        }
        if(list1 or list2){
            if(list1) head->next = list1;
            else head->next = list2;
        }
        return prev.next;
    }
};
