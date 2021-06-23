#include "InfixToPostfix.h"

int GetOpPrec(char op)
{
	switch (op)
	{
	case '*':
	case '/':
		return 5;
	case '+':
	case '-':
		return 3;
	case '(':
		return 1;
	}
	return -1;
}

int WhoPrecOp(char op1, char op2)
{
	int op1Prec = GetOpPrec(op1);
	int op2Prec = GetOpPrec(op2);

	if (op1Prec < op2Prec) return 1;
	else if (op1Prec > op2Prec) return -1;
	else return 0;
}

void ConvToRPNExp(char exp[])
{
	Stack stack;
	int explen = strlen(exp);
	char * convExp = (char*)malloc(explen + 1);
	
	int i, idx = 0;
	char tok, popOp;

	memset(convExp, 0, sizeof(char)*explen + 1);
	StackInit(&stack);

	for (i = 0; i < explen; i++)
	{
		tok = exp[i];
		if (isdigit(tok))
		{
			convExp[idx++] = tok;
		}
		else
		{
			switch (tok)
			{
			case '(':
				SPush(&stack, tok);
				break;
			case ')':
				while (1)
				{
					popOp = SPop(&stack);
					if (popOp == '(')
						break;
					convExp[idx++] = popOp;
				}
				break;
			case '*': case '/':
			case '+': case '-':
				while (!SIsEmpty(&stack) && WhoPrecOp(tok, SPeek(&stack)) >= 0)
				{
					convExp[idx++] = SPop(&stack);
				}
				SPush(&stack, tok);
				break;
			}
		}
	}
	while (!SIsEmpty(&stack))
	{
		convExp[idx++] = SPop(&stack);
	}

	strcpy(exp, convExp);
	free(convExp);
}