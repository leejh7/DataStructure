#pragma once

typedef int BTData;

typedef struct _bTreeNode
{
	BTData data;
	struct _bTreeNode * left;
	struct _bTreeNode * right;
}BTreeNode;

BTreeNode * MakeBTreeNode(void);				//����� ����
BTData GetData(BTreeNode * bt);					// ��忡 ����� �����͸� ��ȯ
void SetData(BTreeNode * bt, BTData data);		// ��忡 �����͸� ����

BTreeNode * GetLeftSubTree(BTreeNode * bt);		// ���� ���� Ʈ�� �ּ� �� ��ȯ
BTreeNode * GetRightSubTree(BTreeNode * bt);	// ������ ���� Ʈ�� �ּ� �� ��ȯ

void MakeLeftSubTree(BTreeNode * main, BTreeNode  * sub);
void MakeRightSubTree(BTreeNode * main, BTreeNode  * sub);

void DeleteTree(BTreeNode * bt);

typedef void (*VisitFuncPtr)(BTData data);

void PreorderTraverse(BTreeNode * bt, VisitFuncPtr action);
void InorderTraverse(BTreeNode * bt, VisitFuncPtr action);
void PostorderTraverse(BTreeNode * bt, VisitFuncPtr action);
