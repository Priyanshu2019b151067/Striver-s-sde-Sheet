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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr){
            return list2;
        }
        if(list2 == nullptr){
            return list1;
        }
        if(list1==nullptr&& list2==nullptr){
            return nullptr;
        }
        ListNode* i= list1;
        ListNode* j = list2;
        ListNode * root = nullptr;
        if(i->val<=j->val){
            root = new ListNode(i->val);
            i = i->next;
        }
        else{
            root = new ListNode(j->val);
            j = j->next;
        }
        ListNode * cmp = root;
        while(i!=nullptr && j!=nullptr){
            if(i->val <= j->val){
                cmp->next = new ListNode(i->val);
                cmp =  cmp->next;
                i = i->next;
            }else{
                    cmp->next = new ListNode(j->val);
                    cmp = cmp->next;
                    j = j->next;
                }
                
        }

        while(j!=nullptr){
            cmp->next = new ListNode(j->val);
            j = j->next;
            cmp = cmp->next;
            
        }
         while(i!=nullptr){
            cmp->next = new ListNode(i->val);
            i = i->next;
            cmp = cmp->next;
            
        }
        return root;
    }
};