#include <stdio.h>

int main(int argc, char *argv[]) {
	char buf[300] = {'\0'};
	int bufptr = 0;
	for (int i = 1; i < argc; i++) {
		
	}



}
int unexpand(FILE *stream) {
	char c;
	char buf[300];
	char spacebuf[16] = {'\0'};
	int spaceptr = 0;
	int bufptr = 0;
	int spacect = 0;
	while ((c = getc(stream)) != EOF) {
		if (spacect == 8) {
			buf[bufptr] = '\t';
			spacect = 0;
			bufptr++;
			continue;
		}
		if (c == ' ') {
			spacect++;
		}
		else if (c == '\n') {
			puts(buf);
			bufptr = 0;
		}
		else
			buf[bufptr] = c;
			
	}
}
