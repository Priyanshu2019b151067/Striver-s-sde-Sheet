
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return NULL;
        if(head->next == NULL || k== 0) return head;
        ListNode * temp = head;
        ListNode * tail = NULL;
        int length = 0;
        while(temp!=NULL){
            tail = temp;
            length++;
            temp = temp->next;
        }
        k = k%length;
        if(k == 0) return head;
        int p = k-1;
        ListNode * slow = head;
        while(p--){
            slow = slow->next;
        }
        ListNode *fast = head;
        ListNode *prev = NULL;ro
        while(slow->next!=NULL){
            prev = fast;
            fast = fast->next;
            slow = slow->next;
        }
        tail->next = head;
        head = fast;
        tail = prev;
        tail->next = NULL;
        return head;
    }
    
};