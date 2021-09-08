#include <stdio.h>
#include "BinaryTree3.h"	// Ʈ���� ������ Ȯ���ϱ� ���ؼ�
#include "BinarySearchTree2.h"

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

	BSTInsert(&avlRoot, 3);
	BSTInsert(&avlRoot, 2);
	BSTInsert(&avlRoot, 4);
	BSTInsert(&avlRoot, 1);
	BSTInsert(&avlRoot, 5);
	BSTInsert(&avlRoot, 6);

	printf("��Ʈ ���: %d \n", GetData(avlRoot));    //3

	clNode = GetLeftSubTree(avlRoot);   //2, ��Ʈ 4�� ����
	crNode = GetRightSubTree(avlRoot);  //6, ��Ʈ 4�� ������
	printf("%d, %d \n", GetData(clNode), GetData(crNode));

	clNode2 = GetLeftSubTree(clNode);    //1, 2�� ����
	printf("%d \n", GetData(clNode2));

	clNode2 = GetLeftSubTree(crNode);    //5, 3�� ����
	crNode2 = GetRightSubTree(crNode);   //8, 3�� ������
	printf("%d, %d \n", GetData(clNode2), GetData(crNode2));

	return 0;
}