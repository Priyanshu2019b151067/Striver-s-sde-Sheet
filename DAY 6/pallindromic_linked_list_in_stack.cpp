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
    bool pallindrome(vector<int> &v){
        int i = 0;
        int j = v.size() -1;
        bool output = true;
        while(i <= j){
            if(v[i]!=v[j]){
                output = false;
                break;
            }
            i++;
            j--;
        }
        return output;
    }
    bool isPalindrome(ListNode* head) {
        if(head == nullptr) return false;
        if(head->next == nullptr) return true;
        ListNode * temp = head;
        stack<int> s;
        while(temp!=nullptr){
            s.push(temp->val);
            temp = temp->next;
        }
        temp = head;
        while(temp != nullptr){
            if(temp->val != s.top()){
                return false;
            }
            temp = temp->next;
            s.pop();
        }
        return true;
    }
};