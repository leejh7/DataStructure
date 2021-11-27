#include <stdio.h>
#include "BinaryTree3.h"	// 트리의 구조를 확인하기 위해서
#include "BinarySearchTree2.h"

void Print(int data)
{
	printf("%d ", data);
}

int main(void)
{
	BTreeNode * avlRoot;
	BTreeNode * clNode;		// current left node
	BTreeNode * crNode;		// current right node

	BTreeNode * clNode2;    
	BTreeNode * crNode2;

	BTreeNode * clNode3;
	BTreeNode * crNode3;

	BSTMakeAndInit(&avlRoot);

	BSTInsert(&avlRoot, 8);
	BSTInsert(&avlRoot, 9);
	BSTInsert(&avlRoot, 10);
	BSTInsert(&avlRoot, 2);
	BSTInsert(&avlRoot, 1);
	BSTInsert(&avlRoot, 5);
	BSTInsert(&avlRoot, 3);
	BSTInsert(&avlRoot, 6);
	BSTInsert(&avlRoot, 4);
	BSTInsert(&avlRoot, 7);
	BSTInsert(&avlRoot, 11);
	BSTInsert(&avlRoot, 12);


//	printf("루트 노드: %d \n", GetData(avlRoot));    //3
//
//	clNode = GetLeftSubTree(avlRoot);   //2, 루트 4의 왼편
//	crNode = GetRightSubTree(avlRoot);  //6, 루트 4의 오른편
//	printf("%d, %d \n", GetData(clNode), GetData(crNode));
//
//	clNode2 = GetLeftSubTree(clNode);    //1, 2의 왼편
//	printf("%d \n", GetData(clNode2));
//
//	clNode2 = GetLeftSubTree(crNode);    //5, 3의 왼편
//	crNode2 = GetRightSubTree(crNode);   //8, 3의 오른편
//	printf("%d, %d \n", GetData(clNode2), GetData(crNode2));

	PreorderTraverse(avlRoot, Print);
	return 0;
}