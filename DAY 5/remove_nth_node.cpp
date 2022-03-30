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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
         if(head == nullptr){
            return nullptr;
        }
        ListNode * first = head;
        ListNode * second = nullptr;

       
//         making second points to the nth element from the begining
        while(n--){
            if(second == nullptr){
                second = head;
            }
            else{
                second = second->next;
            }
        }
        
//  linear traverse the linked list until second points to last element of the array and simulateously 
//   making the first pointer points to the next elements
//     when the second reaches the last element first will point to nth form the end
    // Now keep incrementing both the pointers by one at the same time until the second is pointing to the last node of the linked list.
        ListNode * temp = nullptr;
        while(second->next!=nullptr){
            temp = first;
            first = first->next;
            second = second->next;
        }
        if(temp == nullptr){
            head = head->next;
        }
        else{
            temp->next = first->next;
            delete first;
        }
        return head;
        
        
/*
 1. we have to use two pointers 
    first pointing to head 
    second pointing to nth node from begining.
    we will start iterating over the linked list and make second point to the last element of the linked list and     simulanteously incresing our first pointer  
*/
    }
};