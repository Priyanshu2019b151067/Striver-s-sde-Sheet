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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(head == nullptr) return nullptr;
        
        if(k==1) return head;
        
        ListNode * cmp = head;
        int l = 0;
        while(cmp!=NULL){
            l++;
            cmp = cmp->next;
        }
        ListNode * nex = nullptr;
        ListNode *ohead = nullptr;
        ListNode *otail = nullptr;
        ListNode *ttail = nullptr;
        ListNode *thead = nullptr;
        cmp = head;
        int x = 0;
        while(true){
            int p = k;
            while(p-- && cmp!=NULL){
                nex = cmp->next;
                cmp->next = thead;
                if(thead == NULL){
                    thead = ttail = cmp;
                }else{
                    thead = cmp;
                }
                cmp = nex;
                x++;
            }
            if(ohead == NULL){
                ohead = thead;
                otail = ttail;
            }else{
                otail->next = thead;
                otail = ttail;
            }
            if(l - x < k){
                otail->next = cmp;
                break;
            }
            thead = ttail = nullptr;
            
        }
        return ohead;
        
    }
};