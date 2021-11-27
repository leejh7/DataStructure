#include <stdio.h>
#include <stdlib.h>
#include <stack>

extern inline int max(int a, int b) { return a < b ? b : a; }
enum rotateMenu
{
	LL = 1,
	LR,
	RR,
	RL,
	NO
};

/**
 * AVLNode represents a node in AVL tree.
 */
typedef struct AVLNode
{
	int key, address, height, bf;
	struct AVLNode *left, *right;
} AVLNode;

/**
 * getAVLNode returns a new node.
 * @return a new node
 */
AVLNode *getAVLNode()
{
	AVLNode *node = (AVLNode *)malloc(sizeof(AVLNode));
	node->height = 1;
	node->bf = 0;
	node->left = node->right = NULL;
	return node;
}

typedef AVLNode *AVLTree;

/**
 * height returns the height of T.
 * @param T: an AVL tree
 * @return height of T
 */
int height(AVLTree T)
{
	/* write your code here */
	if (T->left && T->right)
		return max(T->left->height, T->right->height) + 1;
	else if (T->left)
		return T->left->height + 1;
	else if (T->right)
		return T->right->height + 1;
	else
		return 1;
}

int balancingFactor(AVLTree T)
{
	if (T->left && T->right)
		return T->left->height - T->right->height;
	else if (T->left)
		return T->left->height;
	else if (T->right)
		return -(T->right->height);
	else
		return 0;
}

/**
 * rotateLL implements LL rotation in subtree rooted with x.
 * @param T: an AVL tree
 * @param x: root node of subtree
 * @param f: parent node of x
 */
void rotateLL(AVLTree *T, AVLNode *x, AVLNode *f)
{
	/* write your code here */
	AVLNode *cx = x->left;
	x->left = cx->right;
	cx->right = x;

	x->height = height(x);
	x->bf = balancingFactor(x);
	cx->height = height(cx);
	cx->bf = balancingFactor(cx);

	if (f == NULL)
		*T = cx;
	else if (f->left == x)
		f->left = cx;
	else
		f->right = cx;
}

/**
 * rotateRR implements RR rotation in subtree rooted with x.
 * @param T: an AVL tree
 * @param x: root node of subtree
 * @param f: parent node of x
 */
void rotateRR(AVLTree *T, AVLNode *x, AVLNode *f)
{
	/* write your code here */
	AVLNode *cx = x->right;
	x->right = cx->left;
	cx->left = x;

	x->height = height(x);
	x->bf = balancingFactor(x);
	cx->height = height(cx);
	cx->bf = balancingFactor(cx);

	if (f == NULL)
		*T = cx;
	else if (f->left == x)
		f->left = cx;
	else
		f->right = cx;
}

/**
 * rotateLR implements LR rotation in subtree rooted with x.
 * @param T: an AVL tree
 * @param x: root node of subtree
 * @param f: parent node of x
 */
void rotateLR(AVLTree *T, AVLNode *x, AVLNode *f)
{
	/* write your code here */
	AVLNode *cx = x->left;
	rotateRR(T, cx, x);
	rotateLL(T, x, f);
}

/**
 * rotateRL implements RL rotation in subtree rooted with x.
 * @param T: an AVL tree
 * @param x: root node of subtree
 * @param f: parent node of x
 */
void rotateRL(AVLTree *T, AVLNode *x, AVLNode *f)
{
	/* write your code here */
	AVLNode *cx = x->right;
	rotateLL(T, cx, x);
	rotateRR(T, x, f);
}

void rotateTree(AVLTree *T, enum rotateMenu &rotationType, AVLNode *p, AVLNode *q)
{
	switch (rotationType)
	{
	case LL:
		rotateLL(T, p, q);
		break;
	case LR:
		rotateLR(T, p, q);
		break;
	case RR:
		rotateRR(T, p, q);
		break;
	case RL:
		rotateRL(T, p, q);
		break;
	case NO:
		break;
	}
}

/**
* insertBST inserts newKey into T.
*/
void insertBST(AVLTree *T, int newKey)
{
	AVLNode *p = *T;
	AVLNode *q = NULL;

	std::stack<AVLNode*> stack;

	while (p != NULL)
	{
		if (newKey == p->key)
			return;
		
		q = p;
		stack.push(p);

		if (newKey < p->key)
			p = p->left;
		else
			p = p->right;
	}

	AVLNode *y = getAVLNode();
	y->key = newKey;
	
	if (q == NULL)
	{
		*T = y;
	}
	else if (newKey < q->key)
	{
		q->left = y;
	}
	else
	{
		q->right = y;
	}

	while (!stack.empty())
	{
		q = stack.top();
		stack.pop();
		
		q->height = height(q);
	}
}

AVLNode* deleteBST(AVLTree *T, int deleteKey, int &targetKey)
{
	AVLNode *pVRoot = getAVLNode();
	AVLNode *p = *T;
	AVLNode *q = pVRoot;
	AVLNode *d;
	pVRoot->right = *T;

	std::stack<AVLNode*> stack;

	while (p != NULL && p->key != deleteKey)
	{
		q = p;
		stack.push(p);

		if (deleteKey < p->key)
			p = p->left;
		else
			p = p->right;
	}

	if (p == NULL)
		return NULL;

	d = p;

	if (p->left == NULL && p->right == NULL)
	{
		if (q->left == p)
			q->left = NULL;
		else
			q->right = NULL;
	}
	else if (p->left == NULL || p->right == NULL)
	{
		AVLNode * dc;
		if (p->left != NULL)
			dc = p->left;
		else
			dc = p->right;

		if (q->left == p)
			q->left = dc;
		else
			q->right = dc;
	}
	else
	{
		stack.push(p);
		AVLNode * tmpNode = p;
		if (p->left->height - p->right->height > 0)
		{
			p = p->left;
			while (p->right != NULL)
			{
				stack.push(p);
				p = p->right;
			}
			q = stack.top();
			if (q->left == p)
				q->left = p->left;
			else
				q->right = p->left;
		}
		else
		{
			p = p->right;
			while (p->left != NULL)
			{
				stack.push(p);
				p = p->left;
			}
			q = stack.top();
			if (q->left == p)
				q->left = p->right;
			else
				q->right = p->right;
		}
		tmpNode->key = p->key;
		d = p;
	}
	
	
	if (pVRoot->right != *T)
	{
		*T = pVRoot->right;
	}

	if (stack.empty())
	{
		targetKey = NULL;
	}
	else
	{
		targetKey = stack.top()->key;
	}

	while (!stack.empty())
	{
		q = stack.top();
		stack.pop();
		
		q->height = height(q);
	}
	delete pVRoot;
	return d;
}

/**
* checkBalance from newKey to root of T
*/
void checkBalance(AVLTree *T, int newKey, enum rotateMenu &rotationType, AVLNode *p, AVLNode *q, bool &hasRotate)
{
	if (p == NULL)
		return;

	if (newKey < p->key)
		checkBalance(T, newKey, rotationType, p->left, p, hasRotate);
	else if (newKey > p->key)
		checkBalance(T, newKey, rotationType, p->right, p, hasRotate);
	else
		checkBalance(T, newKey, rotationType, NULL, p, hasRotate);

	p->bf = balancingFactor(p);

	if (1 < p->bf)
	{
		if (0 <= p->left->bf)
			rotationType = LL;
		else
			rotationType = LR;
	}
	else if (p->bf < -1)
	{
		if (p->right->bf <= 0)
			rotationType = RR;
		else
			rotationType = RL;
	}
	else
	{
		rotationType = NO;
	}
	rotateTree(T, rotationType, p, q);
	if (q != NULL)
		q->height = height(q);

	if (rotationType != NO && !hasRotate)
	{
		hasRotate = true;
		switch (rotationType)
		{
		case LL:
			printf("LL ");
			break;
		case LR:
			printf("LR ");
			break;
		case RR:
			printf("RR ");
			break;
		case RL:
			printf("RL ");
		default:

			break;
		}
	}
}
/**
 * insertAVL inserts newKey into T.
 * @param T: an AVL tree
 * @param newKey: a key to insert
 */
void insertAVL(AVLTree *T, int newKey)
{
	/* write your code here */
	insertBST(T, newKey);
	AVLNode *p = *T;
	AVLNode *q = NULL;
	enum rotateMenu rotationType = NO;
	bool hasRotate = false;
	checkBalance(T, newKey, rotationType, p, q, hasRotate);
	if (!hasRotate)
		printf("NO ");
}

/**
 * deleteAVL deletes deleteKey from T.
 * @param T: an AVL tree
 * @param deleteKey: a key to delete
 */
void deleteAVL(AVLTree *T, int deleteKey)
{
	/* write your code here */
	int targetKey = 0;
	AVLNode* delNode = deleteBST(T, deleteKey, targetKey);
	AVLNode *p = *T;
	AVLNode *q = NULL;
	enum rotateMenu rotationType = NO;
	bool hasRotate = false;
	checkBalance(T, targetKey, rotationType, p, q, hasRotate);
	if (!hasRotate)
		printf("NO ");
	delete delNode;
}

/**
 * inorderAVL implements inorder traversal in T.
 * @param T: an AVL tree
 */
void inorderAVL(AVLTree T)
{
	/* write your code here */
	if (T == NULL)
		return;

	inorderAVL(T->left);
	printf("%d ", T->key);
	inorderAVL(T->right);
}

int main()
{
	/* DO NOT MODIFY CODE BELOW */
	int testCases[] = { 40, 11, 77, 33, 20, 90, 99, 70, 88, 80, 66, 10, 22, 30, 44, 55, 50, 60, 25, 49 };

	AVLTree T = NULL;

	for (int i = 0; i < 20; i++)
	{
		insertAVL(&T, testCases[i]);
		inorderAVL(T);
		printf("\n");
	}
	for (int i = 0; i < 20; i++)
	{
		deleteAVL(&T, testCases[i]);
		inorderAVL(T);
		printf("\n");
	}
	for (int i = 0; i < 20; i++)
	{
		insertAVL(&T, testCases[i]);
		inorderAVL(T);
		printf("\n");
	}
	for (int i = 19; 0 <= i; i--)
	{
		deleteAVL(&T, testCases[i]);
		inorderAVL(T);
		printf("\n");
	}
}