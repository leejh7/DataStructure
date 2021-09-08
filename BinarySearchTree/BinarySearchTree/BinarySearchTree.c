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

BTreeNode * BSTRemove(BTreeNode ** pRoot, BSTData target)
{
	// 삭제 대상이 루트 노드인 경우를 별도로 고려해야 한다.
	BTreeNode * pVRoot = MakeBTreeNode();	// 가상 루트 노드(가상 루트 노드의 부모 노드)
	BTreeNode * pNode = pVRoot;				// parent node
	BTreeNode * cNode = *pRoot;				// current node
	BTreeNode * dNode;						// delete node

	// 루트 노드를 pVRoot가 가리키는 노드의 오른쪽 자식 노드가 되게 한다.
	ChangRightSubTree(pVRoot, *pRoot);

	// 삭제 대상인 노드를 탐색
	while (cNode != NULL && GetData(cNode) != target)
	{
		pNode = cNode;

		if (target < GetData(cNode))		// target을 찾으려면 cNode의 왼쪽 서브 트리를 탐색해야함
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}

	if (cNode == NULL)		// 삭제 대상이 존재하지 않는다면,
		return NULL;

	dNode = cNode;			// 삭제 대상을 dNode가 가리키게 한다.

	// 첫 번째 경우: 삭제할 노드가 단말 노드인 경우
	if (GetLeftSubTree(dNode) == NULL && GetRightSubTree(dNode) == NULL)
	{
		if (GetLeftSubTree(pNode) == dNode)		// 삭제할 노드가 부모 노드의 왼쪽에 위치한 경우
			RemoveLeftSubTree(pNode);
		else
			RemoveRightSubTree(pNode);
	}

	// 두 번째 경우: 삭제할 노드가 하나의 자식 노드만 갖는 경우
	else if (GetLeftSubTree(dNode) == NULL || GetRightSubTree(dNode) == NULL)
	{
		BTreeNode * dcNode;		// 삭제 대상의 자식 노드 가리킴
		
		if (GetLeftSubTree(dNode) != NULL)
			dcNode = GetLeftSubTree(dNode);
		else
			dcNode = GetRightSubTree(dNode);

		if (GetLeftSubTree(pNode) == dNode)
			ChangLeftSubTree(pNode, dcNode);
		else
			ChangRightSubTree(pNode, dcNode);
	}

	// 세 번째 경우: 두 개의 자식 노드를 모두 갖는 경우
	else
	{
		BTreeNode * mpNode = dNode;
		BTreeNode * mNode = GetRightSubTree(dNode);
		int delData;

		// 삭제 대상의 대체 노드를 찾는다
		while (GetLeftSubTree(mNode) != NULL)
		{
			mpNode = mNode;
			mNode = GetLeftSubTree(mNode);
		}

		// 대체 노드에 저장된 값을 삭제할 노드에 대입한다.
		delData = GetData(dNode);			// 대입 전 삭제 될 데이터 백업
		SetData(dNode, GetData(mNode));		// 대입

		// 대체 노드가 대체 노드의 부모 노드의 왼쪽 자신인 경우
		if (GetLeftSubTree(mpNode) == mNode)
			ChangLeftSubTree(mpNode, GetRightSubTree(mNode));
		else
			ChangRightSubTree(mpNode, GetRightSubTree(mNode));
		

		dNode = mNode;						// 논리적으로는 기존 dNode를 삭제하는 것이지만 실제로는 값의 대입으로 삭제를 대체하며 대체 노드를 삭제한다.
		SetData(dNode, delData);
	}

	// 삭제된 노드가 루트 노드인 경우에 대한 추가적인 처리
	if (GetRightSubTree(pVRoot) != *pRoot)
		*pRoot = GetRightSubTree(pVRoot);

	free(pVRoot);		// 가상 루트 노드의 소멸
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