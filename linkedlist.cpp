#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	struct node *next;
};
struct node *head=NULL;

void display();

void create(){
	cout<<"Enter how many an element of linked list you want to create "<<endl;
	int n;
	cin>>n;
	cout<<"Enter the value"<<endl;
	struct node *temp;
	for(int i=0;i<n;i++){
		int val;
		cin>>val;
		if(head==NULL){
			temp = (struct node *)malloc(sizeof(struct node *));
			temp->data = val;
			temp->next = NULL;
			head = temp;
		}
		else{
			struct node *ptr = head;
			while(ptr->next!=NULL){
				ptr = ptr->next;
			}
			temp = (struct node *)malloc(sizeof(struct node *));
			temp->data = val;
			temp->next = NULL;
			ptr->next = temp;
		}
	}
	display();
}

void display(){
	cout<<"Linked list elements are:-> ";
	struct node *temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}

void insert_beg(){
	cout<<"Enter which element you want to insert in linked list"<<endl;
	int n;
	cin>>n;
	if(head==NULL){
		struct node *temp = (struct node *)malloc(sizeof(struct node *));
		temp->data=n;
		temp->next=NULL;
		head=temp;
	}
	else{
	struct node *newnode = (struct node*)malloc(sizeof(struct node*));
	newnode->data=n;
	newnode->next=head;
	head=newnode;
	}
	display();
	
}

void insert_last(){
	cout<<"Enter element which you want to insert at end"<<endl;
	int n;
	cin>>n;
	if(head==NULL){
		struct node *temp = (struct node *)malloc(sizeof(struct node *));
		temp->data=n;
		temp->next=NULL;
		head=temp;
	}
	else{
	struct node *temp=(struct node *)malloc(sizeof(struct node *));
	temp->data=n;
	temp->next=NULL;
	struct node *curr=head;
	while(curr->next!=NULL){
		curr=curr->next;
	}
	curr->next=temp;
	
	}
	display();
}

void deleteMid()
{
     struct node *slow=head;
     struct node *fast=head;
     struct node *curr=head;

     while(slow && fast->next){
     curr=slow;
     slow=slow->next;
     fast=fast->next->next;
     }
     curr->next=slow->next;
     free(curr->next);
     //return head;
     display();
     cout<<endl;

}

struct node *removeDuplicatesorted(struct node *head)
{
 struct node *curr = head;
 if(head->next==NULL){
 	cout<<"Linked list does not have any element"<<endl;
 }
  while(curr->next!=NULL){
  if(curr->data != curr->next->data)
  curr=curr->next;
  else
  curr->next=curr->next->next;
  //free(curr->next);
  
 }
 return head;
 display();
 cout<<endl;
}

void getNthFromLast()
{
       int n;
       cout<<"Enter nth number which you want to find from linked list "<<endl;
       cin>>n;
       struct node *temp=head;
       int size=0;
       while(temp!=NULL){
       temp=temp->next;
       size++;
       }
       if(n>size){
       cout<<"Size of nth node is greater than linked list"<<endl;
       }
      
       int trav=size-n;
       struct node *curr=head;
       while(trav--){
       curr=curr->next;
       }
       cout<< curr->data<<endl;
}


void reverseList()
{
  struct node *prev=NULL;
  struct node *next;
  struct node *curr=head;
  while(curr!=NULL){
  next=curr->next;
  curr->next=prev;
  prev=curr;
  curr=next;
  }
  head = prev;
  display();
  cout<<endl;

}

void isPalindrome()
{
    struct node *curr=head;
    stack<int>s;
    while(curr!=NULL){
    s.push(curr->data);
    curr=curr->next;
    }
    curr=head;
    int temp;
    while(!s.empty() && curr!=NULL){
    	temp = s.top();
    	s.pop();
    	if(temp!=curr->data){
     	cout<<"Linked list is not palindrom"<<endl;
     	exit(0);
     	//return 0;
    	}
    	curr=curr->next;
    }
    cout<<"Linked list is palindrome"<<endl;
    //return 1;
}

void insert_any(){
	cout<<"Enter the element where you want to insert data"<<endl;
	int mid;
	cin>>mid;
	cout<<"Enter which data you want to insert"<<endl;
	int n;
	cin>>n;
	struct node *curr = head;
	struct node *prev;
	while(curr->next!=NULL && curr->data!=mid){
		prev=curr;
		curr=curr->next;
	}
	struct node *temp=(struct node *)malloc(sizeof(struct node *));
	//curr->next = temp;
	temp->data = n;
	temp->next = curr->next;
	curr->next=temp;
	
	display();
	cout<<endl;
}

void delete_beg(){
	head = head->next;
	display();
	cout<<endl;
}

void delete_last(){
	struct node *curr = head;
	struct node *prev;
	while(curr->next!=NULL){
		prev = curr;
		curr = curr->next;
	}
	prev->next = NULL;
	display();
	cout<<endl;
 }

void delete_any(){
	cout<<"Enter which element you want to delete"<<endl;
	int n;
	cin>>n;
	struct node *curr = head;
	struct node *prev;
	if(head->data == n){
		head = head->next;
		
	}
	else{
	while(curr->next!=NULL && curr->data!=n){
		prev = curr;
		curr = curr->next;
	}
	prev->next = curr->next;
}
	display();
	cout<<endl;
}

int main(){
	
	cout<<"****** Enter to the linked list world *****"<<endl<<endl;
	while(1){
	cout<<"Choose following option"<<endl<<endl;
	cout<<"1. For create linkedlist"<<endl;
	cout<<"2. For insert element from begining in linked list"<<endl;
	cout<<"3. For insert element in middle of linked list"<<endl;
	cout<<"4. For insert element in last of linked list"<<endl;
	cout<<"5. For delete element from begining in linked list"<<endl;
	cout<<"6. For delete element from middle of linked list"<<endl;
	cout<<"7. For delete element from the last of linked list"<<endl;
	cout<<"8. For display linked list"<<endl;
	cout<<"9. For delete mid element from linked list"<<endl;
	cout<<"10. For removing duplicate element from sorted linked list"<<endl;
	cout<<"11. For finding nth last node from linked list"<<endl;
	cout<<"12. For reversing linked list"<<endl;
	cout<<"13. For checking linked list is palindrome or not"<<endl;




	//cout<<"10. For exiting linked list"<<endl;


	int ch;
	cin>>ch;
	
	switch(ch){
		case 1:
			create();
			break;
		case 2:
			insert_beg();
			break;
		case 3:
			insert_any();
			break;
		case 4:
			insert_last();
			break;
		case 5:
			delete_beg();
			break;
		case 6:
			delete_any();
			break;
		case 7:
			delete_last();
			break;
		case 8:
			display();
			break;	
		case 9:
			deleteMid();
			break;	
		case 10:
			head = removeDuplicatesorted(head);
			break;
		case 11:
			getNthFromLast();
				break;
		case 12:
			reverseList();
			break;	
		case 13:
			isPalindrome();
			break;							
		default:
			cout<<"Please Enter Valid option"<<endl;
			break;						
	}
}
	
}
