#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

struct Node
{
 int data;
struct Node* link;
};
struct Node* tail;
struct Node* head;

struct Node* XOR(struct Node *x, struct Node *y) {
 return (struct Node*)((uintptr_t)(x) ^ (uintptr_t)(y));
}

void traverse(struct Node **head_ref)
{
 struct Node* curr = head;
 struct Node* prev = NULL;
 struct Node *next;
 while (curr != NULL)
 {
 printf("%d —> ", curr->data);
 
next = XOR(prev, curr->link);
 
prev = curr;
curr = next;
 }
 printf("NULL");
}
void insert(struct Node **head_ref, int data)
 {
     struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
     newNode->data=data;
     if(head==NULL){
        newNode->link=NULL;
        head = tail = newNode;
     }
     else
     {
         newNode->link = XOR(tail,NULL);
         tail->link = XOR(XOR(tail->link,NULL),newNode);
         tail = newNode;
     }
 }

void push(struct Node **head_ref, int data)
{
 
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
 newNode->data = data;
 
newNode->link = XOR(head, NULL);
 
if (head!=NULL)
 {
 head->link = XOR(newNode, XOR(head->link, NULL));
 }
 head = newNode;
}
int delete(bool from_tail)
 {
     int data;
     struct Node *ptr;
     if(from_tail)
     {
         ptr=tail;
         data=ptr->data;
         struct Node *prev=XOR(ptr->link,NULL);
         if(prev==NULL)
         {
             head=NULL;
         }
         else{
            prev->link=XOR(ptr,XOR(prev->link,NULL));
         }
         tail=prev;
     }
     free(ptr);
     ptr=NULL;
     return data;
 }


int main () 
{ 
    struct Node *head = NULL; 
    int i,ch,ele,x,elem;
    int data;
     
    while(1)
    {printf("\n Enter choice \n 1.Insert at beginning \n 2. Traverse \n 3. Delete \n 4. Insert at end \n 5.exit\n");
    scanf("%d",&ch);
    switch(ch){
      case 1 : printf("\n Element to insert:");
                        scanf("%d", &ele);
                        push(&head, ele); 
                        traverse(&head); 
                        break;
      case 2 : traverse (&head); 
                          break;
      case 3 : 
     printf("Enter the number of values to be deleted from the end?\n");
     scanf("%d",&x);
     for (int i=0;i<x;i++)
     {
         data=delete(i < x);
         printf("Successfully deleted %d\n",data);
         traverse(&head);

     }
     break;
      
    case 4: printf("\n Element to insert:");
                        scanf("%d",&elem);
                        insert(&head,elem); 
                        traverse(&head); 
                        break;
    case 5: exit(0);                   
    }
    
    }
    return 0; 

}

