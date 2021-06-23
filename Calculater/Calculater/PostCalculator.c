#include "PostCalculator.h"

int EvalRPNExp(char exp[])
{
	Stack stack;
	int explen = strlen(exp);
	int i, op1, op2;
	char tok;

	StackInit(&stack);
	for (i = 0; i < explen; i++)
	{
		tok = exp[i];
		if (isdigit(tok))
		{
			SPush(&stack, tok - '0');
		}
		else
		{
			op2 = SPop(&stack);
			op1 = SPop(&stack);
			switch (tok)
			{
			case '*':
				SPush(&stack, op1 * op2);
				break;
			case '/':
				if (op2 == 0)
				{
					printf("0으로 나눌 수 없습니다.");
					exit(-1);
				}
				SPush(&stack, op1 / op2);
				break;
			case '+':
				SPush(&stack, op1 + op2);
				break;
			case '-':
				SPush(&stack, op1 - op2);
				break;
			}
		}
	}
	return SPop(&stack);
}