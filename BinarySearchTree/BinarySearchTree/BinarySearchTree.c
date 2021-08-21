#include "BinarySearchTree.h"

void BSTMakeAndInit(BTreeNode ** pRoot)
{
	*pRoot = NULL;
}

BSTData BSTGetNodeData(BTreeNode * bst)
{
	return GetData(bst);
}

void BSTInsert(BTreeNode ** pRoot, BSTData data)
{
	BTreeNode * pNode = NULL;		// parent node
	BTreeNode * cNode = *pRoot;		// current node
	BTreeNode * nNode = NULL;		// new node

	// ���ο� ��尡(�� �����Ͱ� ��� ��尡) �߰��� ��ġ�� ã�´�.
	while (cNode != NULL)
	{
		if (data == GetData(cNode))
			return;

		pNode = cNode;

		if (GetData(cNode) > data)
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}

	// pNode�� �ڽ� ���� �߰��� �� ����� ����
	nNode = MakeBTreeNode();		// �� ����� ����
	SetData(nNode, data);			// �� ��忡 ������ ����

	// pNode�� �ڽ� ���� �� ��带 �߰�
	if (pNode != NULL)		// �� ��尡 ��Ʈ ��尡 �ƴ϶��(= ù��° ������ �ƴ϶��)
	{
		if (GetData(pNode) > data)
			MakeLeftSubTree(pNode, nNode);
		else
			MakeRightSubTree(pNode, nNode);
	}
	else                   // �� ��尡 ��Ʈ �����(= ù �����̶��)
	{
		*pRoot = nNode;
	}
}

BTreeNode * BSTSearch(BTreeNode * bst, BSTData target)
{
	BTreeNode * cNode = bst;		// current node
	BSTData cd;						// current data

	while (cNode != NULL)
	{
		cd = GetData(cNode);

		if (cd == target)
			return cNode;
		else if (cd > target)
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}

	return NULL;		// Ž������� ����Ǿ� ���� ����.
}
