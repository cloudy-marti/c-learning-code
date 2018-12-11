#include <stdio.h>

void wCount(char* string)
{
	int i, word, line;
	i = word = line = 0;

	for(i = 0; string[i] != '\0'; i++)
	{
		if(string[i] == ' ')
		{
			word++;
		}else if(string[i] == '\n'){
			word++;
			line++;
		}
	}

	printf("in the text above we have :\n- %d characters\n- %d words\n- %d lines\n\n", i, word, line + 1);
}