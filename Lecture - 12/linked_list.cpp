#include<iostream>
using namespace std;

class node{

public:
	int data;
	node* next;

public:
	//Node Constructor
	node(int d){
		data = d;
		next = NULL;
	}
};

/*
class LinkedList{
	node*head;
};
*/
void insertAtHead(node*&head,int data){
	if(head==NULL){
		head = new node(data);
		return;
	}

	//otherwise!
	node* n = new node(data);
	n->next = head;
	head = n;
}
//Insert at tail
void insertAtTail(node*&head,int data){

	if(head==NULL){
		head = new node(data);
		return;
	}
	node*t = head;
	//bring t pointer to the last node
	while(t->next!=NULL){
		t = t->next;
	}
	//last node ->next attach new node
	t->next = new node(data);
	return;
}
int length(node*head){
	int l=0;
	while(head!=NULL){
		l++;
		head = head->next;
	}
	return l;
}

void insertInMiddle(node*&head,int data,int pos){
	if(pos==0){
		insertAtHead(head,data);
		return;
	}
	if(pos>length(head)){
		insertAtTail(head,data);
		return;
	}
	//Middle
	node*t = head;
	for(int jump=1;jump<=pos-1;jump++){
		t = t->next;
	}
	node* n = new node(data);
	n->next = t->next;
	t->next = n;
}

int search1(node*head,int key){
//Iterative Search
	node*t = head;
	int idx = 0;
	while(t!=NULL){
		if(t->data==key){
			return idx;
		}
		idx++;
		t = t->next;
	}
	return -1;
}

int search2(node*head,int key){
//Recursive Search
	//base case
	if(head==NULL){
		return -1;
	}

	//rec case
	if(head->data==key){
		return 0;
	}
	else{
		int l = search2(head->next,key);
		if(l!=-1){
			return 1 + l;
		}
		return l;
	}
}
void reverse(node*&head){
	//iterative way
	node* p = NULL;
	node* c = head;
	node* n = c->next;

	while(c!=NULL){
		//save the next
		n = c->next;
		//make the current point to prev
		c->next = p;
		//update c and p
		p = c;
		c = n;
	}
	head = p;
}
node* reverse_rec(node*head){
	//recursive way
	//base case
	if(head->next==NULL){
		return head;
	}
	//rec case
	node* cHead = reverse_rec(head->next);
	node*t = cHead;
	while(t->next!=NULL){
		t = t->next;
	}
	t->next = head;
	head->next = NULL;
	return cHead;
}
node* reverse_rec_fast(node*head){
	//recursive way
	//base case
	if(head->next==NULL){
		return head;
	}
	//rec case
	node* cHead = reverse_rec_fast(head->next);
	
	head->next->next = head;
	head->next = NULL;
	return cHead;
}

node* midPoint(node*head){
	node*slow = head;
	node*fast = head->next;

	while(fast!=NULL and fast->next!=NULL){
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;

}

node* k_th_from_last(node*head,int k){
	// Homework!
	node*f = head;
	for(int jump=1;jump<=k;jump++){
		f = f->next;
	}
	node*s = head;
	while(f!=NULL){
		f = f->next;
		s = s->next;
	}
	return s;
}

//Let us print our linked list
void print(node *head){
	while(head!=NULL){
		cout<<head->data<<"-->";
		head = head->next;
	}
	cout<<endl;
}
//Get meeting point
bool floyd_cycle(node*head){

	node* slow = head;
	node*fast = head;

	//cycle detection
	while(fast!=NULL and fast->next!=NULL){
		
		fast = fast->next->next;
		slow = slow->next;

		if(fast==slow){
			
			cout<<"First meeting "<<slow->data<<endl;
			slow = head;
			break;
		}
	}
	//find the meeting point
	while(slow!=fast){
		slow = slow->next;
		fast = fast->next;
	}

	cout<<"Meeting point is "<<slow->data<<" ";

	//3. Break the cycle
	// meeting point prev ->next = NULL


	return false;
}

node* merge(node *a,node *b){
	//base case
	if(a==NULL){
		return b;
	}
	if(b==NULL){
		return a;
	}
	//rec case
	node*c;
	if(a->data<b->data){
		c = a;
		c->next = merge(a->next,b);
	}
	else{
		c = b;
		c->next = merge(a,b->next);
	}
	return c;

}

istream& operator>>(istream& a,node*&head){

	int d;
	cin>>d;
	while(d!=-1){
		insertAtTail(head,d);
		a>>d;
	}

	return a;
}
ostream& operator<<(ostream&a,node*head){
	print(head);
	return a;
}



int main(){

	//Linked List
	node*a = NULL;
	node*b = NULL;
	cin>>a>>b;
	cout<<a<<b;
	node*c = merge(a,b);
	cout<<c<<endl;


	/*
	
	insertAtHead(head,5);
	insertAtHead(head,3);
	insertAtHead(head,2);
	insertAtHead(head,1);
	print(head);
	
	insertAtTail(head,1);
	insertAtTail(head,2);
	insertAtTail(head,3);
	insertAtTail(head,4);
	insertAtTail(head,5);
	insertAtHead(head,0);
	print(head);
	//create cycle
	node*t = head;
	while(t->next!=NULL){
		t = t->next;
	}
	t->next = head->next->next;
	floyd_cycle(head);


	
	insertInMiddle(head,4,4);
	
	print(head);
	reverse(head);
	print(head);
	head = reverse_rec_fast(head);
	print(head);
	*/

	return 0;
}