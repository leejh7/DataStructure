#pragma once

#include <stdio.h>
#include "BinaryTree2.h"

typedef BTData BSTData;

// BST�� ���� �� �ʱ�ȭ
void BSTMakeAndInit(BTreeNode ** pRoot);

// ��忡 ����� ������ ��ȯ
BSTData BSTGetNodeData(BTreeNode * bst);

// BST�� ������� ������ ����(����� �������� ����)
void BSTInsert(BTreeNode ** pRoot, BSTData data);

// BST�� ������� ������ Ž��(target�� ��ġ�� ��� �ּҸ� ��ȯ)
BTreeNode * BSTSearch(BTreeNode * bst, BSTData target);
