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
};
