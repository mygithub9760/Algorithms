#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct BSTNode
{
	int data;
	struct BSTNode* left;
	struct BSTNode* right;
};

struct ListNode
{
	int data;
	ListNode* next;
};

ListNode* createListNode(int data)
{
	ListNode* temp = (struct ListNode*) malloc(sizeof(struct ListNode));
	temp->next = NULL;
	temp->data = data;
	return temp;
}

BSTNode* createNode(int data)
{
	BSTNode* temp = (struct BSTNode*) malloc(sizeof(struct BSTNode));
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

void inorder(BSTNode* root)
{
	if(!root) return;
	inorder(root->left);
	printf("%d\n", root->data);
	inorder(root->right);
}

struct BSTNode* insert(int data, BSTNode* root)
{
	if(!root) 
	{
		BSTNode* temp = createNode(data);
		root = temp;
		return root;
	}
	if(data < root->data)
		root->left = insert(data, root->left);
	else if(data > root->data)
		root->right = insert(data, root->right);
	return root;
} 

BSTNode* findMax(BSTNode* root)
{
	if(!root) return NULL;
	if(!root -> right) return root;

	return findMax(root->right);
}

BSTNode* deleteNode(int data, BSTNode* root)
{
	BSTNode* temp;
	
	if(!root) printf("element not found\n");

	if(data < root->data)
		root->left = deleteNode(data, root->left);
	else if(data > root->data)
		root->right = deleteNode(data, root->right);
	else
	{
		if(root->right && root->left)
		{
			temp = findMax(root->left);
			root->data = temp->data;
			root->left = deleteNode(root->data, root->left);
		}
		else
		{
			temp = root;
			if(!root->left && root->right) root = root->right;
			else if(!root->right && root->left) root = root->left;
			else
				root = NULL;
			free(temp);
		}
	}
	return root;
}

bool Search(int key, BSTNode* root)
{
	if(!root) return 0;
	if(key < root->data)
		return Search(key, root->left);
	else if(key > root->data)
		return Search(key, root->right);
	return 1;
}

BSTNode* LCA(BSTNode* a, BSTNode* b, BSTNode* root)
{
	if(!root) return NULL;
	if(root -> data == a->data || root->data == b->data) return root;
	if((root->data > a->data && root->data < b->data) || (root->data < a->data && root->data > b->data))
		return root;
	if(root->data > a->data && root->data > b->data)
		return LCA(a, b, root->left);
	if(root->data < a->data && root->data < b->data)
		return LCA(a, b, root->right);
}

void shortestPath(int a, int b, BSTNode* root)
{
	BSTNode* lca = LCA(createNode(a), createNode(b), root);
	
	int v[10];
	BSTNode* temp = lca;
	int i = 0;
	while(temp -> data != a)
	{
		v[i] = temp->data; i++;
		if(a < temp->data)
			temp = temp->left;
		else if(a > temp->data)
			temp = temp->right;
	}
	v[i] = temp->data; i++;
	temp = lca;
	while(temp->data != b)
	{
		v[i] = temp->data; i++;
		if(b < temp->data)
			temp = temp->left;
		else if(b > temp->data)
			temp = temp->right;
	}
	v[i] = temp->data; 
	
	for(int i = 0; i<5;i++)
		printf("%d\n",v[i]);
}

bool isBST(BSTNode* root)
{
	if(!root) return 1;
	if(!root->left && !root->right) return 1;
	if((root->data > FindMax(root->left)->data)&&(root->data < FindMin(root->right)->data)&&isBStT(root->left)&&isBST(root->right))
		return 1;
	return 0;
}

bool isBSTImproved(BSTNode* root, int min, int max)
{
	if(!root) return 1;
	return (root->data > min && root->data < max && isBSTImproved(root->left, min, root->data) && isBSTImproved(root->right, root->data, max));
}

bool isBSTInorder(BSTNode* root, int prev)
{
	if(!root) return 1;
	if(!isBSTInorder(root->left, prev)) return 0;
	if(root->data < prev) return 0;
	prev = root -> data;
	return isBSTInorder(root->right, prev);
}

BSTNode* concatenate(BSTNode* leftList, BSTNode* rightList)
{
	if(!leftList) return rightList;
	if(!rightList) return leftList;

	BSTNode* leftLast = leftList->left;
	BSTNode* rightLast = rightList->left;

	rightList->left = leftLast;
	leftLast->right = rightList;

	leftList->left = rightLast;
	rightLast->right = leftList;

	return leftList;
}

BSTNode* BSTtoDLL(BSTNode* root)
{
	if(!root) return root;

	BSTNode* leftList = BSTtoDLL(root->left);
	BSTNode* rightList = BSTtoDLL(root->right);

	root->left = root->right = root;

	return concatenate(concatenate(leftList, root), rightList);
}

void printCDLL(BSTNode* head)
{
	if(!head) return;
	BSTNode* temp = head;
	do
	{
		printf("%d\n", temp->data);
		temp = temp->right;
	}
	while(temp != head);
}

BSTNode* findMiddle(BSTNode* head)
{
	BSTNode *slow, *fast;
	slow = fast = head;
	while(fast && fast->right)
	{
		slow = slow -> right;
		fast = fast -> right -> right;
	}
	return slow;
}

BSTNode* DLLtoBST(BSTNode* head)
{
	if(!head || !head->right) return head;
	BSTNode* mid = findMiddle(head);
	mid->left ->right = NULL;
	mid->right ->left = NULL;
	mid->left = DLLtoBST(head);
	mid->right = DLLtoBST(mid->right);
	return mid;

}

void preorder(BSTNode* root)
{
	if(!root) return;

	printf("%d\n", root->data);
	preorder(root->left);
	preorder(root->right);

}

BSTNode* ArrayToBST(int a[], int start, int end)
{
	if(start > end) return NULL;
	if(start == end) return createNode(a[start]);
	int mid = start + (end - start)/2;

	BSTNode* root = createNode(a[mid]);
	root->left = ArrayToBST(a, start, mid-1);
	root->right = ArrayToBST(a, mid+1, end);
	return root;
}

BSTNode* LLtoBST(ListNode* head, int start, int end)   ///// something is wrong
{
	if(start > end) return NULL;

	int mid = start + (end - start)/2;

	BSTNode* leftChild = LLtoBST(head, start, mid -1);

	BSTNode* parent = createNode(head->data);
	parent->left = leftChild;
	head = head->next;
	parent->right = LLtoBST(head, mid+1, end);
	
	return parent;
}

BSTNode* kthSmallest(BSTNode* root, int k)
{
	stack<BSTNode*> S;
	
	while(1)
	{

		while(root)
		{
			S.push(root);
			root = root->left;
		}
		if(S.empty()) {return NULL;}

		root = S.top(); 
		S.pop();
		k--;
		if(k==0)
			return root;
		root = root->right;
	}
}

BSTNode* floor(BSTNode* root, int key)
{
	stack<BSTNode*> S;
	BSTNode* prev = NULL;
	
	while(1)
	{

		while(root)
		{
			S.push(root);
			root = root->left;
		}
		if(S.empty()) {return NULL;}

		root = S.top(); 
		S.pop();
		if(root->data > key) return prev;
		if(root->data == key)  return root;

		prev = root;
		root = root->right;
	}
}

void inRangeK1_K2(BSTNode* root, int K1, int K2)
{
	stack<BSTNode*> S;
	
	while(1)
	{

		while(root)
		{
			S.push(root);
			root = root->left;
		}
		if(S.empty()) {return;}

		root = S.top(); 
		S.pop();
		if(root->data >= K1 && root->data <= K2)
			printf("%d\n", root->data);
		root = root->right;
	}
}

BSTNode* ceil(BSTNode* root, int key)
{
	stack<BSTNode*> S;
	BSTNode* prev = root;
	
	while(1)
	{

		while(root)
		{
			S.push(root);
			root = root->left;
		}
		if(S.empty()) {return NULL;}

		root = S.top(); 
		S.pop();
		if(root->data >= key) return root;

		root = root->right;
	}

}


int main(int argc, char const *argv[])
{
	 struct BSTNode* root = createNode(10);
	root->left = createNode(5);
	root->right = createNode(12);
	root = insert(8,root);


	// BSTNode *one, *two, *three, *four, *five, *six, *seven, *head;
	// one = createNode(1);
	// two = createNode(2);
	// three = createNode(3);
	// four = createNode(4);
	// five = createNode(5);
	// six = createNode(6);
	// seven = createNode(7);

	// head = one;
	// one -> right = two;
	// two ->left = one;

	// two ->right = three;
	// three ->left = two;

	// three ->right = four;
	// four ->left = three;

	// four ->right = five;
	// five ->left = four;

	// five ->right = six;
	// six ->left = five;

	// six ->right = seven;
	// seven ->left = six;

	// root = DLLtoBST(head);


	//root = deleteNode(8, root);
	//printf("%d \n", findMax(root)->data);
	//preorder(root);
	//printf("%d\n", Search(8, root));
	//printf("%d\n", LCA(createNode(5), createNode(8), root)->data);
	//shortestPath(8, 12, root);
	//printf("%d\n", v[0]);
	//BSTNode* head = BSTtoDLL(root);
	//printCDLL(head);
	//printf("%d\n", isBSTInorder(root,-1000));
	// ListNode *one, *two, *three, *four, *five, *six, *seven, *head;
	// one = createListNode(1);
	// two = createListNode(2);
	// three = createListNode(3);
	// four = createListNode(4);
	// five = createListNode(5);
	// six = createListNode(6);
	// seven = createListNode(7);

	// one->next = two;
	// two->next = three;
	// three->next = four;
	// four->next = five;
	// five->next = six;
	// six->next = seven;

	// head = one;

	// while(head)
	// {
	// 	printf("%d\n", head->data);
	// 	head = head ->next;
	// }
	//root = LLtoBST(head,0,6);
	//preorder(root);
	// BSTNode* val = floor(root, 11);
	// if(val)
	// 	printf("%d\n", val->data);
	// else
	// 	printf("no floor exits\n");

	inRangeK1_K2(root, 10, 15);
	return 0;
}
