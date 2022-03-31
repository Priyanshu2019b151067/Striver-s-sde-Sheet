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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == nullptr) return nullptr;
        if(headB == nullptr) return nullptr;
        ListNode * c1 = headA;
        ListNode * c2 = headB;
        unordered_set<ListNode *> us;
        
        ListNode * ans = nullptr;
        while(c1 != NULL && c2!= NULL){
            if(c1 == c2){
                ans = c1;
                break;
            }
            if(us.find(c1)!=us.end()){
                ans = c1;
                break;
            }
            if(us.find(c2)!=us.end()){
                ans = c2;
                break;
            }
            us.insert(c1);
            us.insert(c2);
            c1 = c1->next;
            c2 = c2-> next;
        }
        while(c1!=NULL){
            if(us.find(c1)!=us.end()){
                ans = c1;
                break;
            }
            us.insert(c1);
            c1 = c1->next;
        }
        while(c2!=NULL){
            if(us.find(c2)!=us.end()){
                ans = c2;
                break;
            }
            us.insert(c2);
            c2 = c2->next;
        }
        return ans;
    }
};