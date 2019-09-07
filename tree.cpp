#include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include<stack>
#include <queue> 

using namespace std;

/// Defining structure of tree
struct treeNode
{
	int data;
	struct treeNode* left;
	struct treeNode* right;
};

//// function to create a new node
struct treeNode* createNode(int data)
{
	struct treeNode* temp = (struct treeNode*) malloc(sizeof(struct treeNode));
	temp -> data = data;
	temp -> left = NULL;
	temp -> right = NULL;

	return temp;
}

////////////// VARIOUS TREE TRAVERSALS ///////////////
void preorderTraversal(struct treeNode* root)
{
	stack <struct treeNode*> S;
	vector <int> v;

	while(1)
	{
		while(root)
		{
			printf("%d\n", root -> data);
			S.push(root -> right);
			root = root -> left;
		}
		if (S.empty()) break;
		root = S.top();
		S.pop();
	}
}

void inorderTraversal(struct treeNode* root)
{
	stack <struct treeNode*> S;
	vector <int> v;

	while(1)
	{
		while(root)
		{
			S.push(root);
			root = root -> left;
		}
		if (S.empty()) break;
		root = S.top();
		S.pop();
		printf("%d\n", root -> data);
		root = root -> right;
	}
}

void postorderTraversal(struct treeNode* root)
{
	stack <struct treeNode*> S;
	struct treeNode* previous = NULL;
	do
	{
		while(root)
		{
			S.push(root);
			root = root -> left;
		}

		while(root == NULL && !S.empty())
		{
			root = S.top();
			if(root -> right == NULL || root -> right == previous)
			{
				printf("%d\n", root -> data);

				S.pop();
				previous = root;
				root = NULL;
			}
			else
				root = root -> right;
		}
	}
	while(!S.empty());
}

void levelorderTraversal(struct treeNode* root)
{
	queue <struct treeNode*> Q;
	struct treeNode* temp;
	if(root == NULL) return;
	Q.push(root);
	while(!Q.empty()) 
	{
		temp = Q.front();
		Q.pop();
		printf("%d\n", temp -> data);
		if(temp -> left) Q.push(temp -> left);
		if(temp -> right) Q.push(temp -> right);
	}
}

/////// 1. FINDING MAXIMUM ELEMENT OF THE TREE /////////////
int FindMaxIteration(struct treeNode* root)
{
	int max = -1000;
	struct treeNode* temp;
	queue <struct treeNode*> Q;
	Q.push(root);
	while(!Q.empty())
	{
		temp = Q.front();
		if(max < temp -> data)
			max = temp -> data;
		Q.pop();
		if(temp -> left) Q.push(temp -> left);
		if(temp -> right) Q.push(temp -> right);
	}
	return max;
}

int FindMaxRecrssion(struct treeNode* root)
{
	int max = -1000;
	int root_val;
	int left,right;
	if(root)
	{
		left = FindMaxRecrssion(root -> left);
		right = FindMaxRecrssion(root -> right);
		if(root -> data > right)
			if(root -> data > left)
				max = root -> data;
			else 
				max = left;
		else
			if(right > left)
				max = right;
			else
				max = left;
	}
	return max;
}

///// 2. SEARCHING A GIVEN ELEMENT IN THE TREE //////////////
bool Search(int x, struct treeNode* root)
{
	if(root)
	{
		if(root -> data == x) return true;

		bool temp = Search(x, root -> left);
		if(temp)
			return temp;
		return Search(x, root -> right);
	}
	else
		return false;
}

////////// 3. FINDING SIZE OF THE TREE //////////
int SizeOfTree(struct treeNode* root)
{
	if(!root) return 0;
	return SizeOfTree(root -> left) + 1 + SizeOfTree(root -> right);
}

///////// 4. INSERTING AN ELEMENT INTO THE TREE //////
struct treeNode* Insert(int data, struct treeNode* root)
{
	struct treeNode* newNode = createNode(data);
	queue<struct treeNode*> Q;
	if(!root)
	{ 
		root = newNode;
		return root;
	}
	Q.push(root);
	struct treeNode* temp;
	while(!Q.empty())
	{
		temp = Q.front();
		Q.pop();
		if(temp -> left == NULL)
		{
			temp -> left = newNode;
			return root;
		}
		else 
			Q.push(temp -> left);
		if(temp -> right == NULL)
		{
			temp -> right = newNode;
			return root;
		}
		else 
			Q.push(temp -> right);
	}
	return root; 
}
 
///// 5. REVERSE PRINTING MECHANISM ////////
void ReversePrint(struct treeNode* root)
{
	queue<struct treeNode*> Q;
	stack<struct treeNode*> S;
	struct treeNode* temp;
	Q.push(root);
	while(!Q.empty())
	{
		temp = Q.front();
		Q.pop();
		S.push(temp);
		if(temp -> left) Q.push(temp -> left);
		if(temp -> right) Q.push(temp -> right);
	}

	while(!S.empty())
	{
		cout << S.top() -> data << endl;
		S.pop();
	}
}

///// 6. Deleting tree by post order traversal
void DeleteTree(struct treeNode* root)
{
	stack<struct treeNode*> S;
	struct treeNode* previous = NULL;
	do
	{
		while(root)
		{
			S.push(root);
			root = root -> left;
		}

		while(root == NULL && !S.empty())
		{
			root = S.top();
			if(root -> right == NULL || root -> right == previous)
			{
				free(root);
				S.pop();
				previous = root;
				root = NULL;
			}
			else
				root = root -> right;
		}
	}
	while(!S.empty());
}

///// Deleting tree by level order traversal
void _deleteTree(struct treeNode* root) 
{ 
    // Base Case 
    if (root == NULL) 
        return; 
  
    // Create an empty queue for level order traversal 
    queue<struct treeNode*> q; 
  
    // Do level order traversal starting from root 
    q.push(root); 
    while (!q.empty()) 
    { 
        struct treeNode *node = q.front(); 
        q.pop(); 
  
        if (node->left != NULL) 
            q.push(node->left); 
        if (node->right != NULL) 
            q.push(node->right); 
  
        free(node); 
    } 
}

///// setting root = NULL after deleting the tree
void deleteTree(struct treeNode** node_ref) 
{ 
  DeleteTree(*node_ref); 
  *node_ref = NULL; 
}  


///// 7. HIEGHT OF TREE //////////
int HeightOfTreeRecursive(struct treeNode* root)
{
	if(root == NULL) return 0;
	int l = HeightOfTreeRecursive(root -> left);
	int r = HeightOfTreeRecursive(root -> right);
	
	if(l > r)
		return l + 1;
	else
		return r + 1;
}

int HeightOfTreeIterative(struct treeNode* root)
{
	int level = 0;
	queue<struct treeNode*> Q;
	Q.push(root);
	Q.push(NULL);   /// level marker
	while(!Q.empty())
	{
		root = Q.front();
		Q.pop();

		if(root == NULL)
		{
			if(!Q.empty())
				Q.push(NULL);
			level ++ ;
		}
		else
		{
			if(level == 1) printf("%d\n", root -> data);  /// printing all values at a given level
			if(root -> left)
				Q.push(root -> left);
			if(root -> right)
				Q.push(root -> right);
		}
	}

	return level;
}

///// 8. DEEPEST NODE /////////////
int DeepestNode(struct treeNode* root)
{
	int level = 0;
	queue<struct treeNode*> Q;
	Q.push(root);
	while(!Q.empty())
	{
		root = Q.front();
		Q.pop();

		if(root -> left)
			Q.push(root -> left);
		if(root -> right)
			Q.push(root -> right);
	}

	return root -> data;
}

//// 9. NO OF LEAF NODES ///////
int CountLeafRecursive(struct treeNode* root)
{
	if(root == NULL) return 0;
 	if(root -> left == NULL && root -> right == NULL) return 1;

 	return CountLeafRecursive(root -> left) + CountLeafRecursive(root -> right);
}

int CountLeafIterative(struct treeNode* root)
{
	//// do level order traversal
}

/////// 10. DELETION IN BINARY TREE /////////////

///////// 11. STRUCTURALLY IDENTICAL TREES////////////
bool IsIdentical(struct treeNode* root1, struct treeNode* root2)
{
	if(!root1 && !root2) return true;
	if(!root1 || !root2) return false;

	return (root1 -> data == root2 -> data && IsIdentical(root1 -> left, root2 -> left) && IsIdentical(root1 -> right, root2 -> right));
}


//////// 12. DIAMETER LENGTH//////////
int max(int a, int b)
{
	if(a > b) return a;
	return b;
}
int Diameter(struct treeNode* root)
{
	if(!root)
		return 0;
	int lHeight = HeightOfTreeRecursive(root -> left);
	int rHeight = HeightOfTreeRecursive(root -> right);
	int lDia = Diameter(root -> left);
	int rDia = Diameter(root -> right);

	return max(lHeight + rHeight + 1 , max(lDia, rDia));
}


///////// 13. LEVEL WITH MAX SUM ////////////
int LevelWithMaxSum(struct treeNode* root)
{
	int currentSum = 0;
	int maxSum = 0;
	int currentLevel = 0;
	int maxLevel = 0;
	if(!root) return 0;
	struct treeNode* temp;
	queue<struct treeNode*> Q;
	Q.push(root);
	Q.push(NULL);

	while(!Q.empty())
	{
		temp = Q.front();
		Q.pop();
		if(temp == NULL)
		{
			if(currentSum > maxSum)
			{
				maxSum = currentSum;
				maxLevel = currentLevel;
			}
			currentSum = 0;
			if(!Q.empty())
				Q.push(NULL);
			currentLevel++;
		}
		else
		{
			currentSum = currentSum + temp -> data;
			if(temp -> left) Q.push(temp -> left);
			if(temp -> right) Q.push(temp -> right);
		}
	}

	return maxLevel;
}
////// 14. PRINT FROM ROOT TO LEAF ////////////
void PrintVector(vector<int> v)
{
	for (auto it = v.begin(); it != v.end(); it++) 
        cout << *it << " "; 
}

void PrintFromRootToLeaf(struct treeNode* root, vector<int> v)
{
	if(!root) return;
	v.push_back(root -> data);
	if(!root -> left && !root -> right)
	{
		PrintVector(v);
		cout << "\n";
	}
	else
	{
		PrintFromRootToLeaf(root -> left, v);
		PrintFromRootToLeaf(root -> right, v);
	}
}

//////////// 15. PATH WITH GIVEN SUM ////////////
bool HasPathSum(struct treeNode* root, int sum)
{
	if(!root) return sum == 0;
	int remaining_sum = sum - root -> data;
	if(remaining_sum == 0) return 1;
	if((root -> left && root -> right) || (!root -> left && !root -> right)) 
		return (HasPathSum(root -> left, remaining_sum) || HasPathSum(root -> right, remaining_sum));
	else if(root -> left)
		return HasPathSum(root -> left, remaining_sum);
	else
		return HasPathSum(root -> right, remaining_sum);

}

////// 16. SUM OF ALL ELEMENT ///////
int Add(struct treeNode* root)
{
	if(!root) return 0;
	return root -> data + Add(root -> left) + Add(root -> right);
}

///////// 17. MIRROR MAGE OF A BINARY TREE /////////////
struct treeNode* MirrorImage(struct treeNode* root)
{
	struct treeNode* temp;
	if(root)
	{
		MirrorImage(root -> left);
		MirrorImage(root -> right);

		temp = root -> left;
		root -> left = root -> right;
		root -> right = temp;
	}
	return root;
}

//////// 18. CHECK FOR MIRROR IMAGE ////////////
bool AreMirrorImage(struct treeNode* root1, struct treeNode* root2)
{
	if(!root1 && !root2) return true;
	if(!root1 || !root2) return false;

	if(root1 -> data != root2 -> data) 
		return false;
	else
		return AreMirrorImage(root1 -> left, root2 -> right) && AreMirrorImage(root1 -> right, root2 -> left);
}

//////// 19. LCA /////////////////
struct treeNode* LCA(struct treeNode* root, int a, int b)
{
	if(!root) return root;
	if(a == root -> data || root -> data == b) return root;
	struct treeNode* left = LCA(root -> left, a, b);
	struct treeNode* right = LCA(root -> right, a, b);

	if(left && right) return root;
	return (left ? left : right);
}

////// 20. TREE CONSTRUCTION /////////
struct treeNode* ConstructTree(vector<int> inorder, vector<int> preorder)
{
	///////////////////
	
	int inorderSize = inorder.size();
	int preorderSize = preorder.size();
	
	if(inorderSize < 1 || preorderSize < 1)
	{
		return NULL;
	}

	
	int p = preorder[0];
	
	std::vector<int> l1;
	std::vector<int> l2;

	std::vector<int> r1;
	std::vector<int> r2;

	int i ;
	for(i = 0;i<inorderSize;i++)
	{
		if(inorder[i] == p) break;
		
		if(i+1 < inorderSize){
			l1.push_back(inorder[i]);
			l2.push_back(preorder[i+1]);
		}	
	}

	i++;

	for(;i<inorderSize;i++)
	{
		r1.push_back(inorder[i]);
		
		r2.push_back(preorder[i]);
	}

	
	treeNode* t = createNode(p);
	t->left = ConstructTree(l1, l2);
	t->right = ConstructTree(r1, r2);

	return t;

}

//////// 21. PRINT ALL ANCESTORS //////
void printStack(stack<treeNode*> S)
{
	//cout<< "check4" << endl;
	while(!S.empty()){
		cout << S.top()->data << " ";
		S.pop();
	}
	cout<< endl;
}

void PrintAncestors(struct treeNode* root, struct treeNode* node)
{
	if(!root) return;

	stack<treeNode*> S;
	treeNode* prev = NULL;

	do
	{
		// cout<< "check2" << endl;
		while(root)
		{
			S.push(root);
			root = root -> left;
		}

		while(root == NULL && !S.empty())
		{
			root = S.top();
			if(root->data == node->data)
			{
				S.pop();
				//cout<< "check3" << endl;
				printStack(S);
				//cout<< "check5" << endl;
				return;
			}
			if(root->right == NULL || root->right == prev)
			{
				S.pop();
				prev = root;
				root = NULL;
			}
			else
			{
				//cout<< "check6" << endl;
				root = root ->right;
			}
		}

	}while(!S.empty());
	cout<<" node is not present"<< endl;
}


int main(int argc, char const *argv[])
{
	// struct treeNode* root1 = NULL;
	// root1 = Insert(5,root1);
	// root1 = Insert(6,root1);
	// root1 = Insert(7,root1);
	// root1 = Insert(8,root1);
	// root1 = Insert(9,root1);
	// root1 = Insert(10,root1);
	// root1 = Insert(101,root1);
	// root1 = Insert(12, root1);

	// struct treeNode* root2 = NULL;
	// root2 = Insert(5,root2);
	// root2 = Insert(6,root2);
	// root2 = Insert(7,root2);
	// root2 = Insert(8,root2);
	// root2 = Insert(9,root2);
	// root2 = Insert(10,root2);
	// root2 = Insert(11,root2);

	// treeNode* t = createNode(12);

	std::vector<int> inorder = {8,6,9,5,10,7,101};
	std::vector<int> preorder = {5,6,8,9,7,10,101};

	//inorderTraversal(ConstructTree(inorder, preorder));
	treeNode* t = ConstructTree(inorder, preorder);
	cout << HasPathSum(t,0);
	//PrintAncestors(root1, t);
	// struct treeNode* temp = createNode(6);
	// root -> left = temp;
	// temp = createNode(7);
	// root -> right = temp;
	// temp = createNode(8);
	// root -> left -> left = temp;
	// temp = createNode(9);
	// root -> left -> right = temp;
	// temp = createNode(10);
	// root -> right -> left = temp;
	// temp = createNode(11);
	// root -> right -> right = temp;

	// deleteTree(&root);
	// if(root == NULL) printf("NULL\n");
	//ReversePrint(root);
	//Insert(20, root);
	//preorderTraversal(root1);
	//inorderTraversal(root);
	//postorderTraversal(root);
	//levelorderTraversal(root);
	//printf("%d\n", FindMaxRecrssion(root));
	//printf("%d\n", Search(-6, root));
	//printf("%d\n", SizeOfTree(root));
	//printf("%d\n", DeepestNode(root));
	//HeightOfTreeIterative(root);
	//printf("%d\n", CountLeafRecursive(root));
	//printf("%d\n", IsIdentical(root, root));
	//printf("%d\n", Diameter(root));
	//printf("%d\n", LevelWithMaxSum(root));
	// vector<int> v;
	// PrintFromRootToLeaf(root, v);
	//cout << HasPathSum(root, 12);
	//cout << Add(root);
	//MirrorImage(root1);
	//cout << AreMirrorImage(root2, root1);
	//inorderTraversal(root2);
	// cout << "\n";
	// inorderTraversal(root1);
	//cout << LCA(root1, 8, 9) -> data;
	//cout << FindMaxRecrssion(root1);
	return 0;
}

