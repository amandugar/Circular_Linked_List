#include <stdio.h>
#include <stdlib.h>

struct node{
     int data;
     struct node *next;
 } *head;
 
void begininsert(){
    struct node *ptr,*temp;
    int item;
    ptr = (struct node*)malloc(sizeof(struct node));
    if(ptr==NULL)
        printf("OVERFLOW\n");
    else{
        printf("Enter the data in node\n");
        scanf("%d",&item);
        ptr->data = item;
        if(head==NULL){
            head = ptr;
            ptr->next = head;
        } else {
            temp = head;
            while(temp->next!=NULL)
                temp = temp->next;
            ptr->next = head;
            temp->next = ptr;
            head = ptr;
        }
        printf("Node Inserted");
    }
}

void lastinsert(){
    struct node *temp,*ptr;
    int element;
    ptr = (struct node*)malloc(sizeof(struct node*));
    if(ptr==NULL) printf("OVERFLOW");
    else{
        printf("Enter Data in the node");
        scanf("%d",&element);
        ptr->data = element;
        if(head==NULL){
            head = ptr;
            ptr->next = head;
        } else {
            temp = head;
            while(temp->next!=head){
                temp = temp->next;
            }
            temp->next=ptr;
            ptr->next=head;
        }
        printf("Node Inserted\n");
    }
}

void begin_delete(){
    struct node *ptr;
    if(head==NULL){
        printf("UNDERFLOW\n");
    } else if(head->next==head){
        head = NULL;
        free(head);
        printf("Node Deleted");
    } else {
        ptr = head;
        while(ptr->next!=head)
            ptr = ptr->next;
        ptr->next=head->next;
        free(head);
        head=ptr->next;
        printf("Node Deleted");
    }
}

void end_delete() {
    struct node *ptr,*preptr;
    if(head==NULL) {  
        printf("\nUNDERFLOW");  
    } else if(head->next==head){
        free(head);
        printf("Node Deleted");
    } else {
        ptr = head;
        while(ptr->next!=head){
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = ptr->next;
        free(ptr);
        printf("Node Deleted");
    }
}

void search() {
    struct node *ptr;
    int item,flag=1,i=0;
    ptr = head;
    if(ptr==NULL){
        printf("Empty List");
    } else {
        printf("\nEnter item which you want to search?\n");   
        scanf("%d",&item);  
        if(head ->data == item) {  
        printf("item found at location %d",i+1);  
        flag=0;  
        }  else {
            while(ptr->next!=head){
                if(ptr->data==item){
                    printf("item found at location %d ",i+1);  
                    flag=0;  
                    break;  
                } else flag = 1;
                i++;
                ptr = ptr->next;
            }
        }
        if (flag!=0) printf("Item Not found");
    }
}

void display() {
    struct node *ptr;
    ptr = head;
    if (head == NULL) printf("Nothing to print");
    else{
        printf("Printing Values");
        while(ptr -> next != head) {  
            printf("%d\n", ptr -> data);  
            ptr = ptr -> next;  
        }  
        printf("%d\n", ptr -> data);  
    }  
}

void main ()  
{  
    int choice =0;  
    while(choice != 7)   
    {  
        printf("\n*********Main Menu*********\n");  
        printf("\nChoose one option from the following list ...\n");  
        printf("\n===============================================\n");  
        printf("\n1.Insert in begining\n2.Insert at last\n3.Delete from Beginning\n4.Delete from last\n5.Search for an element\n6.Show\n7.Exit\n");  
        printf("\nEnter your choice?\n");         
        scanf("\n%d",&choice);  
        switch(choice)  
        {  
            case 1:  
            begininsert();      
            break;  
            case 2:  
            lastinsert();         
            break;  
            case 3:  
            begin_delete();       
            break;  
            case 4:  
            end_delete();        
            break;  
            case 5:  
            search();         
            break;  
            case 6:  
            display();        
            break;  
            case 7:  
            exit(0);  
            break;  
            default:  
            printf("Please enter valid choice..");  
        }  
    }  
}  
