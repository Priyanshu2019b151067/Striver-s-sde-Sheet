#include<stdio.h>
#include<stdlib.h>

struct Node {
int data;
struct Node* next;
};

struct Node* create(struct Node* head, int x)
{
struct Node *temp, *ptr = head;
temp = (struct Node*)malloc(sizeof(struct Node));
temp->data = x;
temp->next = NULL;
if (head == NULL)
head = temp;
else {
while (ptr->next != NULL) {
ptr = ptr->next;
}
ptr->next = temp;
}
return head;
}

struct Node* removeNthFromEnd(struct Node* head, int n)
{
 n = n-1;
 struct Node* fast = head;
 while(n--){
     fast = fast->next;
 }
 struct Node * slow = head;
 struct Node * prev = NULL;
 while(fast!=NULL && fast->next!=NULL){
     prev = slow;
     slow = slow->next;
     fast = fast->next;
 }
 prev->next = slow->next;
 slow->next = NULL;
 free(slow);
 return head;
}
void display(struct Node* start)
{
struct Node* temp = start;
while (temp != NULL) {
printf("%d ",temp->data);
temp = temp->next;
}
printf("\n");
}
int main()
{
struct Node* start = NULL;

start = create(start, 1);
start = create(start, 2);
start = create(start, 3);
start = create(start, 4);
start = create(start, 5);
int n = 0;
scanf("%d",&n);
printf("Linked list Input \n");
display(start);
start = removeNthFromLast(start, n);
display(start);
return 0;
}