/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;
        Node *temp = head;
        Node * head2 = NULL;
        Node * temp2  = NULL; 
        unordered_map<Node*,Node*> um;
        while(temp!= NULL){
            if(head2 == NULL){
                head2 = new Node(temp->val);
                temp2 = head2;
            }
            else{
                Node * new_node = new Node(temp->val);
                temp2->next = new_node;
                temp2 = new_node;
            }
            um[temp] = temp2; 
            temp = temp->next;
        }
        temp = head;
        while(temp!=NULL){
            Node * copynode = um[temp];
            if(temp->random==NULL){
                copynode->random = NULL;
            }else{
                copynode->random = um[temp->random];
            } 
            temp = temp->next;              
        }
        return head2;
    }
        
};