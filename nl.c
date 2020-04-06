#include <stdio.h>
#include <stdlib.h>

int radix(int n);

int main(int argc, char **argv) {
	int i;
	char c;
	int line_num = 1;
	int blank_line = 1;
	int line_ptr = 0;
	char line_buf[71] = {'\0'}; // 80 char terminal, 6 spaces for line num, 2 spaces between number and text, null byte 
	int space_count = 0;
	FILE *fp;
	if (argc == 1) {
		while (1) {
		while ((c = getchar()) != '\n' && c != EOF) {
			line_buf[line_ptr] = c;
				line_ptr++;
				if (c != ' ' && c != '\t' && c != '\v') {
					blank_line = 0;
				}
				if (line_ptr == 71) {
					break;
				}
		}
			if (c == EOF)
				break; //break out of while(1)
			if (!blank_line) {
				space_count = 6 - radix(line_num);
				for (int j = 0; j < space_count; j++) { // nested loops for days but we're dealing with known small array sizes
					printf(" ");

				}
				printf("%d  ", line_num);
				for (int k = 0; k < line_ptr; k++) {
					printf("%c", line_buf[k]);
				}
				printf("\n");
				line_num++;
				blank_line = 1;
			}
			else {
			printf("\n");
				}
			line_ptr = 0;
		
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
			while ((c = fgetc(fp)) != '\n' && c != EOF) {
			//	while (c != '\n') {
					line_buf[line_ptr] = c;
					line_ptr++;
					if (c != ' ' && c != '\t' && c != '\v') {
						blank_line = 0;
					}
					if (line_ptr == 71) {
						break;
					}
				}
					if (!blank_line) {
						space_count = 6 - radix(line_num);
						for (int j = 0; j < space_count; j++) { // nested loops for days but we're dealing with known small array sizes
							printf(" ");

						}
						printf("%d  ", line_num);
						for (int k = 0; k < line_ptr; k++) {
							printf("%c", line_buf[k]);
						}
						printf("\n");
						line_num++;
						blank_line = 1;
					}
					else {
					printf("\n");
					}
			//}
			line_ptr = 0;
			if (feof(fp))
				break;
			} while (1); 

			fclose(fp);
			}
		}
	return 0;
}

int radix(int n) {
	int res = 0;
	while(n) {
		res++;
		n /= 10;
	}
	return res;
}
