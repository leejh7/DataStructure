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

	// 새로운 노드가(새 데이터가 담긴 노드가) 추가될 위치를 찾는다.
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

	// pNode의 자식 노드로 추가할 새 노드의 생성
	nNode = MakeBTreeNode();		// 새 노드의 생성
	SetData(nNode, data);			// 새 노드에 데이터 저장

	// pNode의 자식 노드로 새 노드를 추가
	if (pNode != NULL)		// 새 노드가 루트 노드가 아니라면(= 첫번째 삽입이 아니라면)
	{
		if (GetData(pNode) > data)
			MakeLeftSubTree(pNode, nNode);
		else
			MakeRightSubTree(pNode, nNode);
	}
	else                   // 새 노드가 루트 노드라면(= 첫 삽입이라면)
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

	return NULL;		// 탐색대상이 저장되어 있지 않음.
}
