#include "InfixCalculator.h"

int EvalInfixExp(char exp[])
{
	int explen = strlen(exp);
	int result;
	char * expcpy = (char*)malloc(explen + 1);
	strcpy(expcpy, exp);

	ConvToRPNExp(expcpy);
	result = EvalRPNExp(expcpy);
	
	free(expcpy);
	return result;
}