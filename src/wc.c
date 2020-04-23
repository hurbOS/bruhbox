#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
	int i;
	int options[4] = {0};
	int newword = 0;
	int b, w, l, h;
	int optionsselected = 0;
	char *currentfile;
	char currentfilename[50];
	b = w = l = h = 0;
	FILE *fp;
	if (argc == 1) { //currently you can't read from stdin and have options, but that's easily fixable. TODO
		char c;
		while ((c = getchar()) != EOF) {
			if (c == ' ' || c == '\t') {
				newword = 1;
				h++;
			}
			if (c == '\n')
				l++;
			else {
				h++;
				b += (sizeof(c));
				if (newword) {
					w++;
					newword = 0;
				}

			}
		}
	}

	else {
		for (i = 1; i < argc; i++) {
			if (argv[i][0] == '-') {
				char **o = &argv[i]+1;
				char p = **o;
				while (p != '\0') {
					switch (p) {
						case 'l': options[0] = 1;
							  break;
						case 'w': options[1] = 1;
							  break;
						case 'c': options[2] = 1;
							  break;
						case 'm': options[3] = 1;
							  break;
						default:
							  printf("Invalid option, idiot.\n");
							  printf("Usage: wc [OPTIONS] [FILENAME]\n");
							  printf("Options:\n\t-l: lines\n\t-w: words\n\t-c: bytes\n\t-m: characters\n");
							  return 1;
					}
					o++;
					p = **o;
				}
				continue;
			}
			fp = fopen(argv[i], "r");
			if (fp == NULL) {
				printf("wc: %s: No such file, dumbass.", argv[i]);
				return 1;
			}
			snprintf(currentfilename, strlen(argv[i]), argv[i]);
			do {
			char c = fgetc(fp);
			if (feof(fp))
				break;

			if (c == ' ' || c == '\t' || c == '\v') {
				if (newword) {
					w++;
					newword = 0;
				}
				h++;
			}
			else if (c == '\n')
				l++;
			else {
				h++;
				newword = 1;
				}
			b += sizeof(c);
			} while (1); 

			fclose(fp);
			
		int sw,j;
		if (!optionsselected) { //default options
			options[0] = 1;
			options[1] = 1;
			options[3] = 1;
		}
		for (sw = 0; sw < 4; sw++) { //make this more scalable as more options added
			j = options[sw];
			if (j) {
				switch(sw) {
					case 0:
						printf("%d ", l);
						break;
					case 1:
						printf("%d ", w);
						break;
					case 2:
						printf("%d ", h);
						break;
					case 3:
						printf("%d ", b);
						break;

			}
		}

	}
	printf("%s\n", currentfilename);
	}
	}
	return 0;
}
