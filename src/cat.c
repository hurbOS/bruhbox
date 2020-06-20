#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	FILE *fp;
	if (argc == 1) {
		char c;
		while ((c = getchar()) != EOF) {
			printf("%c", c);
		}
	}
	else {
		for (int i = 1; i < argc; i++) {
			fp = fopen(argv[i], "r");
			if (fp == NULL) {
				printf("cat: %s: No such file, dumbass.", argv[i]);
				return 1;
			}

			do {
			char c = fgetc(fp);
			if (feof(fp))
				break;
			printf("%c", c);
			} while (1); 

			fclose(fp);
			}
		}
	return 0;
}
