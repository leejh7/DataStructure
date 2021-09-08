#pragma once

typedef int BTData;

typedef struct _bTreeNode
{
	BTData data;
	struct _bTreeNode * left;
	struct _bTreeNode * right;
}BTreeNode;

BTreeNode * MakeBTreeNode(void);				// ����� ����
BTData GetData(BTreeNode * bt);					// ��忡 ����� �����͸� ��ȯ
void SetData(BTreeNode * bt, BTData data);		// ��忡 �����͸� ����

BTreeNode * GetLeftSubTree(BTreeNode * bt);		// ���� ���� Ʈ�� �ּ� �� ��ȯ
BTreeNode * GetRightSubTree(BTreeNode * bt);	// ������ ���� Ʈ�� �ּ� �� ��ȯ

void MakeLeftSubTree(BTreeNode * main, BTreeNode  * sub);
void MakeRightSubTree(BTreeNode * main, BTreeNode  * sub);

void DeleteTree(BTreeNode * bt);				// bt�� ��Ʈ ����� Ʈ���� ���� (Remove�� ���̰� ����!)


// ���� �ڽ� ��带 Ʈ������ ����, ���ŵ� ����� �ּ� ���� ��ȯ�ȴ�.
BTreeNode * RemoveLeftSubTree(BTreeNode * bt);

// ������ �ڽ� ��带 Ʈ������ ����, ���ŵ� ����� �ּ� ���� ��ȯ�ȴ�.
BTreeNode * RemoveRightSubTree(BTreeNode * bt);

// �޸� �Ҹ��� �������� �ʰ� main�� ���� �ڽ� ��带 �����Ѵ�.
void ChangLeftSubTree(BTreeNode * main, BTreeNode * sub);

// �޸� �Ҹ��� �������� �ʰ� main�� ������ �ڽ� ��带 �����Ѵ�.
void ChangRightSubTree(BTreeNode * main, BTreeNode * sub);


typedef void (*VisitFuncPtr)(BTData data);

void PreorderTraverse(BTreeNode * bt, VisitFuncPtr action);
void InorderTraverse(BTreeNode * bt, VisitFuncPtr action);
void PostorderTraverse(BTreeNode * bt, VisitFuncPtr action);
