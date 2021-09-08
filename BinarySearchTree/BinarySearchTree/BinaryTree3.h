#pragma once

typedef int BTData;

typedef struct _bTreeNode
{
	BTData data;
	struct _bTreeNode * left;
	struct _bTreeNode * right;
}BTreeNode;

BTreeNode * MakeBTreeNode(void);				// 노드의 생성
BTData GetData(BTreeNode * bt);					// 노드에 저장된 데이터를 반환
void SetData(BTreeNode * bt, BTData data);		// 노드에 데이터를 저장

BTreeNode * GetLeftSubTree(BTreeNode * bt);		// 왼쪽 서브 트리 주소 값 반환
BTreeNode * GetRightSubTree(BTreeNode * bt);	// 오른쪽 서브 트리 주소 값 반환

void MakeLeftSubTree(BTreeNode * main, BTreeNode  * sub);
void MakeRightSubTree(BTreeNode * main, BTreeNode  * sub);

void DeleteTree(BTreeNode * bt);				// bt가 루트 노드인 트리를 삭제 (Remove와 차이가 있음!)


// 왼쪽 자식 노드를 트리에서 제거, 제거된 노드의 주소 값이 반환된다.
BTreeNode * RemoveLeftSubTree(BTreeNode * bt);

// 오른쪽 자식 노드를 트리에서 제거, 제거된 노드의 주소 값이 반환된다.
BTreeNode * RemoveRightSubTree(BTreeNode * bt);

// 메모리 소멸은 수반하지 않고 main의 왼쪽 자식 노드를 변경한다.
void ChangLeftSubTree(BTreeNode * main, BTreeNode * sub);

// 메모리 소멸은 수반하지 않고 main의 오른쪽 자식 노드를 변경한다.
void ChangRightSubTree(BTreeNode * main, BTreeNode * sub);


typedef void (*VisitFuncPtr)(BTData data);

void PreorderTraverse(BTreeNode * bt, VisitFuncPtr action);
void InorderTraverse(BTreeNode * bt, VisitFuncPtr action);
void PostorderTraverse(BTreeNode * bt, VisitFuncPtr action);
