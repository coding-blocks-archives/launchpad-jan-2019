#include<iostream>
#include<vector>
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

bool search(node*root,int key){
	//base case(kahi nahi mila)
	if(root==NULL){
		return false;
	}
	//yaha pe mila
	if(root->data==key){
		return true;
	}
	//subtree me mila
	bool leftMeiMila = search(root->left,key);
	if(leftMeiMila){
		return true;
	}
	return search(root->right,key);
}

void printAtLevelK(node*root,int k){
	if(root==NULL){
		return;
	}
	//otherwise
	if(k==0){
		cout<<root->data<<" ";
	}
	printAtLevelK(root->left,k-1);
	printAtLevelK(root->right,k-1);
	return;
}
void levelOrder1(node*root){

	int h = height(root);
	for(int k=0;k<h;k++){
		printAtLevelK(root,k);
		cout<<endl;
	}

}
void mirror(node*root){
	if(root==NULL){
		return;
	}
	swap(root->left,root->right);
	mirror(root->left);
	mirror(root->right);
}

int sumOfNodes(node*root){
	if(root==NULL){
		return 0;
	}
	return root->data + sumOfNodes(root->left) + sumOfNodes(root->right);
}

int replaceSumOfNodes(node*root){
	if(root==NULL){
		return 0;
	}
	if(root->left==NULL and root->right==NULL){
		return root->data;
	}
	//rec case
	int leftSum = replaceSumOfNodes(root->left);
	int rightSum = replaceSumOfNodes(root->right);
	int temp = root->data;
	root->data = leftSum + rightSum;
	return root->data + temp;
}

int diameter(node*root){
	//largest distance btw any two nodes!
	if(root==NULL){
		return 0;
	}
	int op1 = height(root->left) + height(root->right);
	int op2 = max(diameter(root->left),diameter(root->right));
	return max(op1,op2);
}

class Pair{
	public:
		int height;
		int diam;

		Pair(){
			height=diam=0;
		}
};

Pair diamFast(node*root){
		//Base case
		Pair p;
		if(root==NULL){
			return p;
		}
		// rec case(post order - or bottom up approach!)
		Pair left = diamFast(root->left);
		Pair right = diamFast(root->right);

		int op1 = left.height + right.height;
		int op2 = max(left.diam,right.diam);

		p.diam = max(op1,op2);
		p.height = max(left.height,right.height)+1;
		return p;
}
int i=0;

node* buildTreeInPre(int *in,int *pre,int s,int e){
	static int i = 0;
	if(s>e){
		return NULL;
	}
	//rec case
	node *root = new node(pre[i]);
	//linear search
	int j=0;
	for(j=s;j<=e;j++){
		if(in[j]==pre[i]){
			break;
		}
	}
	i++;

	//j -->mid point 
	//recursively build left and right subtree
	root->left = buildTreeInPre(in,pre,s,j-1);
	root->right = buildTreeInPre(in,pre,j+1,e);
	return root;
}

void root2LeafAllPaths(node*root,vector<int> &v){

	if(root==NULL){
		return;
	}

	if(root->left==NULL and root->right==NULL){
		v.push_back(root->data);
		for(int i=0;i<v.size();i++){
			cout<<v[i]<<" --> ";
		}
		cout<<endl;
		v.pop_back();
		return;
	}
	//rec case
	v.push_back(root->data);
	root2LeafAllPaths(root->left,v);
	root2LeafAllPaths(root->right,v);
	v.pop_back();
	return;
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
	*/

	int pre[] = {1,2,4,5,6,3,7};
	int in[] = {4,2,6,5,1,3,7};

	int n = sizeof(pre)/sizeof(int);

	node*root = buildTreeInPre(in,pre,0,n-1);
	levelOrder1(root);

	vector<int> v;
	root2LeafAllPaths(root,v);


	return 0;
}