#include <stdio.h>

int main(int argc, char *argv[]) {
	char c;
	FILE *fp;
	int i = 0;
	// implement getopt TODO
	if (argv[1]) 
		fp = fopen(argv[1], "r");
	else fp = stdin;
	while ((c = getc(fp)) != EOF) {
		printf("%c", c);
		if (c == '\n')
			i++;
		if (i == 10)
			break;
	}
	return 0;
}
