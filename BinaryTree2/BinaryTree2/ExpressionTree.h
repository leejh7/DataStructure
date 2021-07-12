#pragma once

#include "BinaryTree2.h"

BTreeNode * MakeExpTree(char exp[]);		// ���� Ʈ�� ����
int EvaluateExpTree(BTreeNode * bt);		// ���� Ʈ�� ���

void ShowPrefixTypeExp(BTreeNode * bt);		// ���� ǥ��� ��� ���
void ShowInfixTypeExp(BTreeNode * bt);		// ���� ǥ��� ��� ���
void ShowPostfixTypeExp(BTreeNode * bt);	// ���� ǥ��� ��� ���
