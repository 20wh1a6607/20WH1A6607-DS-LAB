#include<stdio.h>
#include<stdlib.h>
void insert_front();
void insert_end();
void display();
int count_node();
void search();
void delete_front();
void delete_end();

int count;

typedef struct sll
   {
    int data;
    struct sll *link;
   }node;
  node*head= NULL;

int main(){
	int ch,x;
    while(1){
    printf("enter choice:\n");
    scanf("%d",&ch);
    printf("1.insert front\n 2.insert end\n 3.display\n 4.count\n 5.search\n 6.delete front\n 7.delete end\n");
    switch(ch){
    	case 1:
    		insert_front();
			break;
		case 2:
            insert_end();
            break;
        case 3:
            display();
        case 4:
            x=count_node();
			printf("number of nodes=%d",x);
		case 5:
			search();
		case 6:
			delete_front();
        case 8:
            exit(0);
}
}
}
void insert_front(){
	int x;
	node*p = malloc(sizeof(node));
	printf("enter value of x:");
	head = p;
	scanf("%d",&x);
	p->data = x;
	p->link = head;
}
void insert_end(){
	int x;
	node*p = malloc(sizeof(node));
	printf("enter the value of x:");
	scanf("%d",&x);
	p->data = x;
	p->link=NULL;
	if(head==NULL){
	head = p;
}
    else{
	node*t = head;
	while(t->link != NULL){
	t = t->link;
    }
	t->link = p;
    }
    }
void display(){
    if(head != NULL){
	node*t=head;
	while(t!=NULL){
	printf("%d\n",t->data);
	t = t->link;
}
}
	else{
	printf("single linked list is empty");
	}
}
int count_node(){
int count = 0;
node*v = head;
if(head==NULL){
return count;
}
else{
while(v!=NULL){
count++;
v=v->link;
}
}
return count;
}
void search(){
	int key;
	node*t = head;
	printf("enter key:");
	scanf("%d",&key);
	while(t!=NULL){
	if(t->data == key){
	printf("key is found");
	break;
}
    else{
	t = t->link;
}
}
	if(t==NULL){
	printf("not found");
	}
}
void delete_front(){
	node*t = head;
    printf("the deleted one is %d",head->data);
	head=head->link;
	free(t);
	}
void delete_end(){
	node*t = head,*p;
	if(head==NULL)
	printf("list is empty");
	while(t->link=NULL)
	{
		t=p;
		t=t->link;
	}
	p->link=NULL;
        free(t);
		if(head->link==NULL)
		head=NULL;
	}
