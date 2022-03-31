class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == nullptr) return nullptr;
        if(headB == nullptr) return nullptr;
        ListNode * c1 = headA;
        ListNode * c2 = headB;
        int length_A = 0;
        int length_B = 0;
        while(c1!= NULL){
            length_A++;
            c1 = c1->next;
        }
        while(c2!= NULL){
            length_B++;
            c2 = c2->next;
        }
        int diff = 0;
        c1 = headA;
        c2 = headB;
        if(length_A > length_B){
            diff = length_A - length_B;
            while(diff--){
                c1 = c1->next;
            }
        }
        else if(length_B > length_A){
            diff = length_B - length_A;
            while(diff--){
                c2 = c2->next;
            }
        }
        
        while(c1!=c2){
            c1 = c1->next;
            c2 = c2->next;
        }
        return c1;
        
    }
};