#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
using namespace std;

class node{
public:
	int data;
	node*left;
	node*right;

	node(int d){
		data = d;
		left = right = NULL;
	}
};
void print(node*root){
	if(root==NULL){
		return;
	}
	cout<<root->data<<" ";
	print(root->left);
	print(root->right);
}
void printIn(node*root){
	if(root==NULL){
		return;
	}
	printIn(root->left);
	cout<<root->data<<" ";
	printIn(root->right);
}
void printPost(node*root){
	if(root==NULL){
		return;
	}
	
	printPost(root->left);
	printPost(root->right);
	cout<<root->data<<" ";
}
void bfs_2(node*root){

	queue<node*> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()){
		node* t = q.front();
		
		if(t==NULL){
			cout<<endl;
			q.pop();
			if(!q.empty()){
				q.push(NULL);
			}
			continue;
		}

		cout<<t->data<<" ";
		q.pop();



		if(t->left){
			q.push(t->left);
		}
		if(t->right){
			q.push(t->right);
		}
	}
	return ;
}

//try to insert a data into a bst
node* insertInBST(node*root,int data){
	if(root==NULL){
		return new node(data);
	}
	if(data<=root->data){
		root->left = insertInBST(root->left,data);
	}
	else{
		root->right = insertInBST(root->right,data);
	}
	return root;
}



node* buildTreeLevelWise(){

	int d;
	cout<<"Root Data ";
	cin>>d;

	node*root = new node(d);
	queue<node*> q;
	q.push(root);

	while(!q.empty()){

		node*f = q.front();
		q.pop();

		cout<<"Enter children of "<<f->data<<" ";
		int c1,c2;
		cin>>c1>>c2;

		if(c1!=-1){
			f->left = new node(c1);
			q.push(f->left);
		}
		if(c2!=-1){
			f->right = new node(c2);
			q.push(f->right);
		}
	}
	return root;
}

void takeInput(node*&root){
	int d;
	cin>>d;
	while(d!=-1){
		root = insertInBST(root,d);
		cin>>d;
	}
	return;
}

node* arr2bst(int *arr,int s,int e){
	//base case
	if(s>e){
		return NULL;
	}

	int mid = (s+e)/2;
	node*root = new node(arr[mid]);
	root->left = arr2bst(arr,s,mid-1);
	root->right = arr2bst(arr,mid+1,e);
	return root;

}

int findNoOfTrees(int n){
	if(n==0){
		return 1;
	}

	int ans =0;
	for(int i=1;i<=n;i++){
		ans += findNoOfTrees(n-i)*findNoOfTrees(i-1);
	}
	return ans;

}

node* deleteInTree(node*root,int key){
	if(root==NULL){
		return NULL;
	}
	if(root->data==key){
		//ise delete krna
		//1. no child
		if(root->left==NULL and root->right==NULL){
			delete root;
			return NULL;
		}
		else if(root->left==NULL and root->right!=NULL){
			node*temp = root->right;
			delete root;
			return temp;
		}
		else if(root->right==NULL and root->left!=NULL){
			node*temp = root->left;
			delete root;
			return temp;
		}
		else{
			//find the inorder successor
			node*temp = root->right;
			while(temp->left!=NULL){
				temp = temp->left;
			}
			root->data  = temp->data;
			root->right = deleteInTree(root->right,root->data);
			return root;
		}
	}
	else if(root->data<key){
		//right mei se delete hoga 
		root->right = deleteInTree(root->right,key);
	}
	else{
		root->left = deleteInTree(root->left,key);
	}
	return root;
}

class LinkedList{
public:
	node*head;
	node*tail;
};

LinkedList convertTree2LL(node*root){
	LinkedList l;
	if(root==NULL){
		l.head = l.tail =NULL;
		return l;
	}
	//Leaf Node
	if(root->left==NULL and root->right==NULL){
		l.head = l.tail = root;
		return l;
	}
	//Left Child
	if(root->left!=NULL and root->right==NULL){
		LinkedList leftLL = convertTree2LL(root->left);
		leftLL.tail->right = root;
		l.head = leftLL.head;
		l.tail = root;
		return l;
	}
	else if(root->left==NULL and root->right!=NULL){
		LinkedList rightLL = convertTree2LL(root->right);
		//leftLL.tail->right = root;
		root->right = rightLL.head;
		l.head = root;
		l.tail = rightLL.tail;
		return l;
	}
	else{
		LinkedList leftLL = convertTree2LL(root->left);
		LinkedList rightLL = convertTree2LL(root->right);
		leftLL.tail->right = root;
		root->right = rightLL.head;
		l.head = leftLL.head;
		l.tail = rightLL.tail;
		return l;
	}
}

bool isBST(node*root,int minV,int maxV){
	if(root==NULL){
		return true;
	}

	//Rec Case
	if(root->data >=minV and root->data<=maxV and isBST(root->left,minV,root->data) and 
		isBST(root->right,root->data,maxV)){
		return true;
	}
	return false;
}



int main(){
	/*
	node*root = buildTree();
	print(root);
	cout<<endl;
	printIn(root);
	cout<<endl;
	printPost(root);

	cout<<"Height "<<height(root)<<endl;
	cout<<"Count "<<countNodes(root)<<endl;
	//printAtLevelK(root,2);
	levelOrder1(root);

	replaceSumOfNodes(root);
	levelOrder1(root);
	cout<<diameter(root)<<endl;
	cout<<"Diam fast "<<diamFast(root).diam<<endl;
	

	int pre[] = {1,2,4,5,6,3,7};
	int in[] = {4,2,6,5,1,3,7};

	int n = sizeof(pre)/sizeof(int);

	node*root = buildTreeInPre(in,pre,0,n-1);
	levelOrder1(root);

	vector<int> v;
	root2LeafAllPaths(root,v);

	*/


	node*root = NULL;
	//takeInput(root);

	int arr[] = {1,3,4,5,7,8,9,10};
	int n = sizeof(arr)/sizeof(int);

	root = arr2bst(arr,0,n-1);
	bfs_2(root);

	printIn(root);

	if(isBST(root,INT_MIN,INT_MAX)){
		cout<<"BST ";
	}
	else{
		cout<<"Not a BST!";
	}

	//cin>>n;
	//cout<<findNoOfTrees(n)<<endl;

	/*
	int key;
	cin>>key;
	cout<<endl;
	root = deleteInTree(root,key);
	cout<<endl;
	bfs_2(root);
	cout<<endl;
	
	LinkedList l = convertTree2LL(root);
	node*temp = l.head;
	while(temp!=NULL){
		cout<<temp->data<<"-->";
		temp = temp->right;
	}
	*/

	//printIn(root);


	return 0;
}