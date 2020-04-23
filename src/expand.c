#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	int i;
	FILE *fp;
	if (argc == 1) {
		char c;
		while ((c = getchar()) != EOF) {
			if (c == '\t') {
				printf("        ");
				continue;
			}
			printf("%c", c);
		}
	}
	else {
		for (i = 1; i < argc; i++) {
			fp = fopen(argv[i], "r");
			if (fp == NULL) {
				printf("cat: %s: No such file, dumbass.", argv[i]);
				return 1;
			}

			do {
			char c = fgetc(fp);
			if (feof(fp))
				break;
			if (c == '\t') {
				printf("        ");
				continue;
			}

			printf("%c", c);
			} while (1); 

			fclose(fp);
			}
		}
	return 0;
}
