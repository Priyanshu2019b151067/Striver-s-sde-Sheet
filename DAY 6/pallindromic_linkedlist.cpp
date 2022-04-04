/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode * find_middle(ListNode * head){
        ListNode * slow = head;
        ListNode * fast = head;
        while(fast!=NULL && fast->next!= NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    bool isPalindrome(ListNode* head) {
      if(head == NULL) return false; 
      if(head->next == NULL) return true;
      ListNode * mid = find_middle(head);
      ListNode * th = nullptr;
      ListNode * tt = nullptr;
      ListNode * nex = nullptr;
      while(mid!=NULL){
          nex = mid->next;
          mid->next = th;
          if(th == NULL){
              th = tt = mid;
          }
          else{
              th = mid;
          }
          mid = nex;
      }
      ListNode * c2 = th;
      ListNode * c1 = head;
      while(c1!= tt && c2 != NULL){
          if(c1->val!=c2->val){
              return false;
          }
          c1 = c1->next;
          c2 = c2->next;
      }
        return true;
    }
};