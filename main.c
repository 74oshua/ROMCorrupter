#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char **argv)
{
	if (argv[1] == 0)
	{
		return 0;
	}
	
	int * fileCont = malloc(1);
	int i = 0;
	int bts = 0;
	
	srand(time(NULL));
	
	FILE * file = fopen(argv[1], "r");
	
	do
	{
		fileCont = realloc(fileCont, (i + 1) * sizeof(int));
		fileCont[i] = fgetc(file);
		i++;
	}
	while (fileCont[i - 1] != EOF);
	
	i = 0;
	
	fclose(file);
	
	file = fopen(argv[1], "w");
	
	while (fileCont[i] != EOF)
	{
		if (rand() % atoi(argv[2]) == 0 && i >= atoi(argv[3]) && i < atoi(argv[4]) && (char)fileCont[i] != 0)
		{
			fputc(rand() % 255, file);
			bts++;
		}
		else
		{
			fputc((char)fileCont[i], file);
		}
		
		i++;
	}
	
	fclose(file);
	
	free(fileCont);
	
	printf("0x%x bytes affected\n", bts);
	
    return 0;
}
