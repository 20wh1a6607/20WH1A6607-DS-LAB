 	include<stdio.h>
int linearSearch1(int[] ,int , int);
	int main(){
	        int a[30],n,i,x,p;
	        printf("Enter size of list:");
	        scanf("%d" , &n);
	        printf("Elements of array:");
	        for(i=0;i<n;i++){
	                scanf("%d" ,&a[i]);
	        }
	        printf("Element to be searched:");
	        scanf("%d",&x);
	        p = linearSearch1(a,n,x);
	        if(p == -1){
	             printf("Element not found");
	        }
	        else{
	             printf("Element found at position %d :",p);
	        }
	}
	int i=0;
	int linearSearch1(int a[],int n,int x){
	        if(a[i]==x){
	                return i;
	        }
	        if(i<n){
	                i++;
	                linearSearch1(a,n,x);
	        }
	        if(i>=n){
	                return -1;
	        }
	}
