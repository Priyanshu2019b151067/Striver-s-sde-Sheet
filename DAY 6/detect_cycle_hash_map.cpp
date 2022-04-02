/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
    if(head == nullptr) return false;
     ListNode * cmp = head;
     bool output = false;
     unordered_set<ListNode *> um;
     while(cmp!= nullptr)
     {
         if(um.find(cmp)!= um.end()){
             output = true;
             break;
         }
         um.insert(cmp);
         cmp = cmp->next;
     }
     return output;
    }
};