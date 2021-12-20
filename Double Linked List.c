#include<stdio.h>
#include<stdlib.h>


struct node{
    int data;
    struct node*link;
};
struct node*head = NULL,*cur,*temp,*temp1;
struct node*create(){
    int n;
    printf("Enter no. of nodes:");
    scanf("%d",&n);
    while(n--){
            cur = (struct node*)malloc(sizeof(struct node));
            scanf("%d",&(cur->data));
            cur->link=NULL;
            if(head==NULL){
                head = cur;
            }
            else{
                temp=head;
                while(temp->link!=NULL){
                    temp=temp->link;
                }
                temp->link=cur;
            }
    }
    return head;
 }


 struct node*insert_begin(int ele){
    cur = (struct node*)malloc(sizeof(struct node));
    cur->data=ele;
    cur->link=head;
    head=cur;
    return head;
 }


struct node*insert_end(int ele){
    cur = (struct node*)malloc(sizeof(struct node));
    cur->data=ele;
    cur->link=NULL;
    temp=head;
    while(temp->link!=NULL){
            temp=temp->link;
    }
    temp->link=cur;
    return head;
 }


 struct node*insert_pos(int pos,int ele){
    int c=1;
    cur = (struct node*)malloc(sizeof(struct node));
    cur->data=ele;
    temp=head;
    while(c<pos-1){
            temp=temp->link;
            c++;
    }
    cur->link=temp->link;
    temp->link=cur;
    return head;
 }


 struct node*delete_begin(struct node*head){
    temp=head;
    head=temp->link;
    printf("deleted element %d",temp->data);
    free(temp);
    return head;
 }


 struct node*delete_end(struct node*head){
    temp=head;
    while(temp->link!=NULL){
            temp1=temp;
            temp=temp->link;
    }
    temp1->link=NULL;
    printf("deleted element %d",temp->data);
    free(temp);
    return head;
 }


 struct node*delete_pos(struct node*head,int pos){
    temp=head;
    int c=1;
    while(c<pos){
            temp1=temp;
            temp=temp->link;
            c++;
    }
    temp1->link=temp->link;
    printf("deleted element %d",temp->data);
    free(temp);
    return head;
 }


 void display(struct node*head){
    temp = head;
    while(temp != NULL){
            printf(" %d ->",temp->data);
            temp = temp->link;
    }
 }


void reverse_display(struct node*head){
    if(head!=NULL){
            reverse_display(head->link);
            printf("%d->",head->data);
    }
 }


int search(struct node*head,int key){
    int c=1;
    temp=head;
    while(temp!=NULL){
            if(key==temp->data){
                return c;
            }
            temp=temp->link;
            c++;
    }
    return -1;
 }


struct node*sorting(struct node*head){
    int x;
    temp=head;
    while(temp!=NULL){
            temp1=temp->link;
            while(temp1!=NULL){
                    if(temp->data>temp1->data){
                            x=temp->data;
                            temp->data=temp1->data;
                            temp1->data=x;
                    }
                    temp1=temp1->link;
            }
            temp=temp->link;
    }
    return head;
 }


int main(){
    int ch,ele,pos,key;
    while(1){
        printf("\n1-create\n2-insert at begin\n3-insert at end\n4-insert at pos\n5-delete at begin\n6-delete at end\n7-delete at pos\n8-display\n9-reverse display\n10-search\n11-sort\n12-exit\n");
        printf("\nEnter your choice : ");
        scanf("%d",&ch);
        switch(ch){
            case 1 : head = create();
                     break;
            case 2 : scanf("%d",&ele);
                     head = insert_begin(ele);
                     break;
            case 3 : scanf("%d",&ele);
                     head = insert_end(ele);
                     break;
            case 4 : scanf("%d",&pos);
                     scanf("%d",&ele);
                     head = insert_pos(pos,ele);
                     break;
            case 5 : head = delete_begin(head);
                     break;
            case 6 : head = delete_end(head);
                     break;
            case 7 : scanf("%d",&pos);
                     head = delete_pos(head,pos);
                     break;
            case 8 : display(head);
                     break;
            case 9 : reverse_display(head);
                     break;
            case 10 : scanf("%d",&key);
                      pos = search(head,key);
                      if(pos==-1){
                            printf("element not found");
                      }
                      else{
                        printf("element found at %d",pos);
                      }
                      break;
            case 11 : head = sorting(head);
                      break;
            case 12 : exit(0);
        }
    }
 }



