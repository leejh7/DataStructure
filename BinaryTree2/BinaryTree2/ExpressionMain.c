#include <stdio.h>
#include "ExpressionTree.h"

int main()
{
	char exp[] = "12+7*";
	BTreeNode * eTree = MakeExpTree(exp);

	printf("전위 표기법의 수식: ");
	ShowPrefixTypeExp(eTree);

	printf("\n중위 표기법의 수식: ");
	ShowInfixTypeExp(eTree);

	printf("\n후위 표기법의 수식: ");
	ShowPostfixTypeExp(eTree);

	printf("\n연산의 결과: %d \n", EvaluateExpTree(eTree));
}
