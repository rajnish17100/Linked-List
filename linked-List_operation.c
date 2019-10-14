#include<stdio.h>
#include<stdlib.h>
// creating self referential structure
struct node{
 	int data;
	struct node* link;
  };

/* declaring three pointers to of structure type ...start pointer will storethe address of the first node, 
   newnode pointer is used to take the address of new node created dynamically 
   temp pointer is used to iterate through the node
 */
struct node* start=NULL;
struct node* temp=NULL;
struct node* newnode=NULL;

struct node* getNewNode(){
	int key;
	struct node* newnode=NULL;
	printf("Enter the data item \n");
	scanf("%d",&key);
	newnode=(struct node*)malloc(sizeof(struct node)); //malloc explicitly returns void pointer so type casting is necessary
	newnode->data=key;
	newnode->link=NULL;
	return newnode;
}

void printLinkedList(){
	temp=start;
	if(temp==NULL){
   	printf("Linked-List is empty...Please Press 1 to create Linked-List\n\n");
    return;
   }
   
    printf("\n Data item in the linked list are :");
    
    while(temp!=NULL){
	 printf(" %d ",temp->data);
	 temp=temp->link;
    }
}


void createLinkedList(){
  int ch;	
  start=getNewNode();
  temp=start;

// creating the linked-List    
  do{
    newnode=getNewNode();
	temp->link=newnode;
    temp=newnode;
	printf("again want to add new element ?? Enter 0 false  or 1 true \n");
    scanf("%d",&ch);
  }while(ch==1);	
}

void insertNewElement(){
 int ch,element;
 printf("Enter the palce at which u want to insert the new element\nPress 1 to insert at begining ..2 for end ...3 for middle: ");
 scanf("%d",&ch);
 
 switch(ch){
 	case 1:
 		newnode=getNewNode();
 		newnode->link=start;
 		start=newnode;
 		break;
 	case 2:
 		//checking whether list contain some element
	  	if(start==NULL){
	  		printf("List is Empty..Please press 1 to create a list\n");
	  		return;
		  }
 		newnode=getNewNode();
 		//Now we have to first reach to the last node
		temp=start;
		while(temp->link!=NULL){
			temp=temp->link;
		}
		//now we reach at the last node now insert the new node and do the changes
		temp->link=newnode;
		break;   	
    case 3:
    	//checking whether list contain some element
    	if(start==NULL){
	  		printf("List is Empty..Please press 1 to create a list\n");
	  		return;
		  }
        printf("\nEnter the element after which u want to insert the new node: ");
 		scanf("%d",&element); //we could have store the value in the key variable also.
 		newnode=getNewNode();
 		//Now we have to first reach to the element after which we want to insert
		temp=start;
		while(temp->data!=element){
			temp=temp->link;
		}
		//now we reach at the required node now insert the new node and do the changes
		newnode->link=temp->link;
		temp->link=newnode;
		break;	
	default:
	    break;	
   }	

}

void deleteElement(){
 int ch,element;
 printf("Enter the palce from fwhere u want to delete the new element\nPress 1 to delete first node .. 2 for last node  ... 3 for middle node: ");
 scanf("%d",&ch);
 
 switch(ch){
 	case 1:
 		//checking whether list contain some element
	  	if(start==NULL){
	  		printf("List is Empty..Deletion can not be performed\n");
	  		return;
		}
 		struct node* t=start;
 		start=start->link;
 		free(t);
 		break;
 	case 2:
 		//checking whether list contain some element
	  	if(start==NULL){
	  		printf("List is Empty..Deletion can not be performed\n");
	  		return;
		  }
 	
 		//Now we have to first reach to the second last node
		temp=start;
		while(temp->link->link!=NULL){
			temp=temp->link;
		}
		//now we reach at the second last node now delete the last node and do the changes
		 t=temp->link;
		temp->link=NULL;
		free(t);
		break;   	
    case 3:
    	//checking whether list contain some element
    	if(start==NULL){
	  		printf("List is Empty..Deletion can not be performed\n");
	  		return;
		  }
        printf("\nEnter the element  which u want to delete from the middle: ");
 		scanf("%d",&element); //we could have store the value in the key variable also.
 		
 		//Now we have to first reach to the element after which we want to delete the node
		temp=start;
		while(temp->link->data!=element){
			temp=temp->link;
		}
		//now we reach at the required node now delete the  node and do the changes
	    t=temp->link;
	    temp->link=temp->link->link;
	    free(t);
		break;	
	default:
	    break;	
   }		

}


int main(){

do{

	int ch;
	printf("\nEnter your choice\nPress 1 to create new linked-list\nPress 2 for inserting the new element at the appropriate position\nPress 3 to delete a node\nPress 4 to print the list\n");
	scanf("%d",&ch);
	
	switch(ch){
	
		case 1:
		  createLinkedList();
		  break;
		
		case 2:
		  insertNewElement();
		  break;
		
		case 3:
		  deleteElement();
		  break;
		
		case 4:
		  printLinkedList();
		  break;
		
		default:
		  return 0;
   }
}while(1);






}
