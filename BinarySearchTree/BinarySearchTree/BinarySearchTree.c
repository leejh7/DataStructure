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

BTreeNode * BSTRemove(BTreeNode ** pRoot, BSTData target)
{
	// ���� ����� ��Ʈ ����� ��츦 ������ ����ؾ� �Ѵ�.
	BTreeNode * pVRoot = MakeBTreeNode();	// ���� ��Ʈ ���(���� ��Ʈ ����� �θ� ���)
	BTreeNode * pNode = pVRoot;				// parent node
	BTreeNode * cNode = *pRoot;				// current node
	BTreeNode * dNode;						// delete node

	// ��Ʈ ��带 pVRoot�� ����Ű�� ����� ������ �ڽ� ��尡 �ǰ� �Ѵ�.
	ChangRightSubTree(pVRoot, *pRoot);

	// ���� ����� ��带 Ž��
	while (cNode != NULL && GetData(cNode) != target)
	{
		pNode = cNode;

		if (target < GetData(cNode))		// target�� ã������ cNode�� ���� ���� Ʈ���� Ž���ؾ���
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}

	if (cNode == NULL)		// ���� ����� �������� �ʴ´ٸ�,
		return NULL;

	dNode = cNode;			// ���� ����� dNode�� ����Ű�� �Ѵ�.

	// ù ��° ���: ������ ��尡 �ܸ� ����� ���
	if (GetLeftSubTree(dNode) == NULL && GetRightSubTree(dNode) == NULL)
	{
		if (GetLeftSubTree(pNode) == dNode)		// ������ ��尡 �θ� ����� ���ʿ� ��ġ�� ���
			RemoveLeftSubTree(pNode);
		else
			RemoveRightSubTree(pNode);
	}

	// �� ��° ���: ������ ��尡 �ϳ��� �ڽ� ��常 ���� ���
	else if (GetLeftSubTree(dNode) == NULL || GetRightSubTree(dNode) == NULL)
	{
		BTreeNode * dcNode;		// ���� ����� �ڽ� ��� ����Ŵ
		
		if (GetLeftSubTree(dNode) != NULL)
			dcNode = GetLeftSubTree(dNode);
		else
			dcNode = GetRightSubTree(dNode);

		if (GetLeftSubTree(pNode) == dNode)
			ChangLeftSubTree(pNode, dcNode);
		else
			ChangRightSubTree(pNode, dcNode);
	}

	// �� ��° ���: �� ���� �ڽ� ��带 ��� ���� ���
	else
	{
		BTreeNode * mpNode = dNode;
		BTreeNode * mNode = GetRightSubTree(dNode);
		int delData;

		// ���� ����� ��ü ��带 ã�´�
		while (GetLeftSubTree(mNode) != NULL)
		{
			mpNode = mNode;
			mNode = GetLeftSubTree(mNode);
		}

		// ��ü ��忡 ����� ���� ������ ��忡 �����Ѵ�.
		delData = GetData(dNode);			// ���� �� ���� �� ������ ���
		SetData(dNode, GetData(mNode));		// ����

		// ��ü ��尡 ��ü ����� �θ� ����� ���� �ڽ��� ���
		if (GetLeftSubTree(mpNode) == mNode)
			ChangLeftSubTree(mpNode, GetRightSubTree(mNode));
		else
			ChangRightSubTree(mpNode, GetRightSubTree(mNode));
		

		dNode = mNode;						// �������δ� ���� dNode�� �����ϴ� �������� �����δ� ���� �������� ������ ��ü�ϸ� ��ü ��带 �����Ѵ�.
		SetData(dNode, delData);
	}

	// ������ ��尡 ��Ʈ ����� ��쿡 ���� �߰����� ó��
	if (GetRightSubTree(pVRoot) != *pRoot)
		*pRoot = GetRightSubTree(pVRoot);

	free(pVRoot);		// ���� ��Ʈ ����� �Ҹ�
	return dNode;
}

void ShowIntData(int data)
{
	printf("%d ", data);
}

void BSTShowAll(BTreeNode * bst)
{
	InorderTraverse(bst, ShowIntData);
}