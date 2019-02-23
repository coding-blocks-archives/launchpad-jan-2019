#include<iostream>
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

node* buildTree(){
	int d;
	cin>>d;
	//Base Case
	if(d==-1){
		return NULL;
	}

	node*root = new node(d);
	root->left = buildTree();
	root->right = buildTree();
	return root;
}
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
int countNodes(node *root){
	if(root==NULL){
		return 0;
	}
	return countNodes(root->left) + 1 + countNodes(root->right);

}
int height(node*root){
	if(root==NULL){
		return 0;
	}
	int h1 = height(root->left);
	int h2 = height(root->right);
	return max(h1,h2) +1;
}



int main(){

	node*root = buildTree();
	print(root);
	cout<<endl;
	printIn(root);
	cout<<endl;
	printPost(root);

	cout<<"Height "<<height(root)<<endl;
	cout<<"Count "<<countNodes(root)<<endl;
	return 0;
}