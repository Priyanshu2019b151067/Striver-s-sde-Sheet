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
    ListNode* middleNode(ListNode* head) {
       ListNode * temp = head;
//         Length of LL
        int count = 0;
        while(temp!=NULL){
            count++;
            temp  = temp->next;
        }
        int mid  = count/2;
        int i = 0;
        temp = head;
        while(i!=mid){
            temp = temp->next;
            i++;
        }
        return temp;
    }
};