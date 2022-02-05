#include<iostream>
using namespace std;
class node{
	public:
		node *next;
		int data;
		node(){
			next=NULL;
			data=0;
		}
		node(int d){
			data=d;
		}
};
class Queue{
	public:
	node *front;
	node *rear;
	Queue(){
		front=rear=NULL;
	}
	void AddMember(int d){       //Enqueue
		node *n=new node;
		n->data=d;
		if(isEmpty()){
			front=rear=n;
			return;	
		}
		rear->next=n;
		rear=n;
	}
	void RemoveMember(){           //Dequeue
		if(!isEmpty()){
				node *todel=new node;
				todel=front;
				front=front->next;
				todel->next=NULL;
				delete(todel);
		}
		else{
				cout<<"Queue Underflow\n";
			}
	}
	bool isEmpty(){
		if(front==NULL){
			return true;
		}
		else{
			return false;
		}
	}
	void display(){
		cout<<endl;
		if (front == NULL) {
	            printf("\nQueue is Empty\n");
	    }
	    else{
	        	node *temp=front;
				while(temp!=NULL){
					cout<<temp->data<<"->";
					temp=temp->next;
				}
		    }
	}
};
int main(){
	Queue obj;
	obj.AddMember(2);
	obj.AddMember(1);
	obj.AddMember(8);
	obj.display();
	obj.RemoveMember();
	obj.display();
}
