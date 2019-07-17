/*
 ============================================================================
 Name        : c_permutation.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int permuta = 0;
typedef enum _OPTIONS {COMBINATION, PERMUTATION} OPTIONS;

int checkdupes(char *str, char c)
{
	int i;
	for (i = 0; i < strlen(str); i++)
		if (str[i] == c)
			return 1;

	return 0;
}

void permute(char *str, char *p, OPTIONS perm)
{
	if (strlen(str) == strlen(p))
	{
		printf("Permutation %d - \"%s\"\n", ++permuta, p);

		return;
	}

	char buff[10];
	int i;
	for (i = 0; i < strlen(str); i++) {
		sprintf(buff, "%s%c", p, *(str+i));
		// printf("%s", buff);
		if (perm == PERMUTATION && !checkdupes(p, str[i]))
			permute(str, buff, perm);
		else
		if (perm == COMBINATION)
			permute(str, buff, perm);
	}

}

int main(void) {
    char str[] = "abcd";

    permute(str, "", COMBINATION);

	return EXIT_SUCCESS;
}
